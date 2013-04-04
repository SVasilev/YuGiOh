#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "image_manager.h"

image_manager::image_manager() : imageMap(), dir()
{

}

image_manager::~image_manager()
{
    imageMap.clear();
    dir.clear();
}

//loads an image using its filename
const sf::Texture& image_manager::get_texture(const std::string& filename)
{
    //checks if image exists
    for (std::map <std::string, sf::Image>::const_iterator it = imageMap.begin();
                it != imageMap.end(); it++)
    {
        if (filename == it -> first)
        {
            std::cout << filename << " image is found." << std::endl;
            sf::Texture texture;
            texture.loadFromImage(it->second);
            return texture;
        }

    }

    //adds the image to map if it doesnt exist
    sf::Image image;

    //search projcet's main dir
    if (image.loadFromFile(filename))
    {
        imageMap[filename] = image;
        std::cout << filename << " image added." << std::endl;
        sf::Texture texture;
        texture.loadFromImage(imageMap[filename]);
        return texture;
    }

    //if not found in main dir, search all other registered dirs
    for (std::vector <std::string>::iterator it = dir.begin();
            it != dir.end(); it++)
    {
        if (image.loadFromFile( (*it) + filename))
        {
            imageMap[filename] = image;
            std::cout << filename << " image added." << std::endl;
            sf::Texture texture;
            texture.loadFromImage(imageMap[filename]);
            return texture;
        }
    }

    std::cout << filename << " image is not found. It is filled with empty image." << std::endl;
    imageMap[filename] = image;
    sf::Texture texture;
    texture.loadFromImage(imageMap[filename]);
    return texture;
}


//delete an image object from the map
void image_manager::delete_image(const sf::Image& image)
{
    for (std::map <std::string, sf::Image>::iterator it = imageMap.begin();
            it != imageMap.end(); it++)
    {
        if(&image == &it->second)
		{
			imageMap.erase(it);
            //return;
		}
    }
}

void image_manager::delete_image(const std::string& filename)
{
    for (std::map <std::string, sf::Image>::iterator it = imageMap.find(filename);
            it != imageMap.end(); it++)
    {
        if (it != imageMap.end())
        {
            imageMap.erase(it);
            //return;
        }
    }
}

void image_manager::add_resource_directory(const std::string& directory)
{
    //check whether the path already exists
    for (std::vector <std::string>::const_iterator it = dir.begin();
                it != dir.end(); it++)
    {
        //the directory is found
        if (directory == (*it))
        {
            return;
        }
    }

    //add new directory
    dir.push_back(directory);
}

void image_manager::remove_resource_directory(const std::string& directory)
{
    for (std::vector <std::string>::iterator it = dir.begin();
                it != dir.end(); it++)
    {
        //deletes the directory
        if (directory == (*it))
        {
            dir.erase(it);
        }
    }
}

