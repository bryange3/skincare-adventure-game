# Choose Your Skincare Game
## Background
I look forward to doing my skincare routine every morning and evening. It is a time to relax and practice some self-care
before starting the day or before going to bed. I created this light-hearted game to test your skincare knowledge and to
pass on some of the things I have learned over the years from various online sources.

## Usage
#### Objective
Your goal is to select the best skincare products for a skincare routine. The higher the number of points a product has,
the better it is considered. Try to gain as many points as you can. I hope you enjoy the game and learn something new
about how to take care of your skin!
#### Instructions
To make routine and product selections type the name of the routine or product you want to select and click the "return"
key on your keyboard. The game will follow the procedure:
1. Enter your name.
2. Choose a skincare routine to go through.
3. Select products under each category in your selected routine. After each product selection, you will be informed of
how many points you have earned and a message regarding the skincare product you chose.
4. View your final game score!

## Building the Project
This project was developed on macOS and may not work on other platforms. This project uses Cinder which can be
downloaded at [https://libcinder.org/](https://libcinder.org/). After you have downloaded Cinder, create this project
within the Cinder folder. Cinder is used for the visual and audial aspect of this game.
External libraries used: Cinder, JsonCpp
#### Setting up JsonCpp
JsonCpp is used to load in data about the skincare products used for the game. More information on JsonCpp can be found
at [https://github.com/open-source-parsers/jsoncpp](https://github.com/open-source-parsers/jsoncpp).
Make sure to add the following code to your CMakeLists.txt file and adjust it to your project directories/paths:

```
set(jsoncpp_DIR "/Users/bryange/Documents/CS126/vcpkg/packages/jsoncpp_x64-osx/share/jsoncpp/")
find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(skincare-game PRIVATE jsoncpp_object jsoncpp_static)

ci_make_app(
        APP_NAME        cinder-skincare-game
        CINDER_PATH     ${CINDER_PATH}
        SOURCES apps/cinder_app_main.cc ${SOURCE_FILES}
        INCLUDES        include
        LIBRARIES       jsoncpp_object jsoncpp_static
)
```
