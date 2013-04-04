#ifndef IMGAGE_MANAGER_H
#define IMGAGE_MANAGER_H

class image_manager
{
    public:
        image_manager();
        ~image_manager();

    private:
        image_manager(const image_manager& );
        image_manager& operator= (const image_manager&);

    public:
        const sf::Texture& get_texture(const std::string& filename);

        void delete_image(const sf::Image& image);
        void delete_image(const std::string& filename);

        void add_resource_directory(const std::string& directory);
        void remove_resource_directory(const std::string& directory);

    private:
        std::map <std::string, sf::Image> imageMap;
        std::vector <std::string> dir;

};

#endif
