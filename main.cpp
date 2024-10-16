#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <number_of_coordinates>" << std::endl;
        return 1;
    }

    int num_coords = std::atoi(argv[1]);
    if (num_coords <= 0)
    {
        std::cerr << "Please enter a valid number of coordinates." << std::endl;
        return 1;
    }

    std::srand(std::time(0)); 

    Coordinate *list_beginning = NULL;
    Coordinate *list_end = NULL;


    for (int i = 0; i < num_coords; ++i)
    {
        float x = static_cast<float>(rand() % 100) / 10; 
        float y = static_cast<float>(rand() % 100) / 10; 

        if (list_beginning == NULL)
        {

            list_beginning = new Coordinate();
            list_beginning->x = x;
            list_beginning->y = y;
            list_beginning->coord_id = ++id_counter;
            list_beginning->next = NULL;
            list_beginning->previous = NULL;
            list_end = list_beginning;
        }
        else
        {
            add_coordinate(list_end, x, y);
        }
    }

    std::cout << "Coordinates (forward display):" << std::endl;
    forward_display(list_beginning);

    std::cout << "\nCoordinates (backward display):" << std::endl;
    backward_display(list_end);


    int delete_id = rand() % num_coords + 1;
    std::cout << "\nDeleting coordinate with ID: " << delete_id << std::endl;
    delete_coordinate(list_beginning, delete_id);

    std::cout << "\nCoordinates after deletion (forward display):" << std::endl;
    forward_display(list_beginning);


    float find_x = 5.0, find_y = 5.0;
    std::cout << "\nFinding closest point to (" << find_x << ", " << find_y << "):" << std::endl;
    closest_to(list_beginning, find_x, find_y);

    return 0;
}

