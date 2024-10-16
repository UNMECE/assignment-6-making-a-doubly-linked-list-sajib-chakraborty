#include "coordinate.h"


int id_counter = 0;

void add_coordinate(Coordinate *&list_end, float x, float y)
{
    Coordinate *new_coord = new Coordinate();
    new_coord->x = x;
    new_coord->y = y;
    new_coord->coord_id = ++id_counter;
    new_coord->next = NULL;
    new_coord->previous = list_end;

    if (list_end != NULL)
        list_end->next = new_coord;

    list_end = new_coord;
}

void forward_display(Coordinate *list_beginning)
{
    Coordinate *current = list_beginning;
    while (current != NULL)
    {
        std::cout << "ID: " << current->coord_id << " X: " << current->x << " Y: " << current->y << std::endl;
        current = current->next;
    }
}

void backward_display(Coordinate *list_end)
{
    Coordinate *current = list_end;
    while (current != NULL)
    {
        std::cout << "ID: " << current->coord_id << " X: " << current->x << " Y: " << current->y << std::endl;
        current = current->previous;
    }
}

void delete_coordinate(Coordinate *&list_beginning, int coord_id_to_delete)
{
    Coordinate *current = list_beginning;

    while (current != NULL && current->coord_id != coord_id_to_delete)
        current = current->next;

    if (current != NULL)
    {
        if (current->previous != NULL)
            current->previous->next = current->next;

        if (current->next != NULL)
            current->next->previous = current->previous;

        if (current == list_beginning)
            list_beginning = current->next;

        delete current;
        std::cout << "Coordinate with ID " << coord_id_to_delete << " deleted." << std::endl;
    }
    else
    {
        std::cout << "Coordinate with ID " << coord_id_to_delete << " not found." << std::endl;
    }
}

int list_length(Coordinate *list_beginning)
{
    int length = 0;
    Coordinate *current = list_beginning;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

void closest_to(Coordinate *list_beginning, float x, float y)
{
    Coordinate *current = list_beginning;
    Coordinate *closest = NULL;
    float min_distance = -1;

    while (current != NULL)
    {
        float distance = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));

        if (min_distance == -1 || distance < min_distance)
        {
            min_distance = distance;
            closest = current;
        }

        current = current->next;
    }

    if (closest != NULL)
    {
        std::cout << "Closest point to (" << x << ", " << y << ") is ID: " << closest->coord_id 
                  << " at (" << closest->x << ", " << closest->y << ") with distance: " << min_distance << std::endl;
    }
}

