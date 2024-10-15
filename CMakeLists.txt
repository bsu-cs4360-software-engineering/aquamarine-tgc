cmake_minimum_required(VERSION 3.14)
project(CardGame)

list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.5.3/msvc2019_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

cmake_policy(SET CMP0135 NEW)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/msvc2019_64")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_compile_options(/Zc:__cplusplus /permissive-)
endif()

# Set include directories for local headers
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Find Qt6
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Add your main game executable (console version)
add_executable(CardGameConsole 
    mainConsole.cpp
    card.cpp
    deck.cpp
    game.cpp
)

# Add the GUI version executable
add_executable(CardGameGUI
    main.cpp
    mainwindow.cpp
    cardwidget.cpp
    card.cpp
    deck.cpp
    game.cpp
)

# Add the test executable
add_executable(CardGameTests 
    TestMain.cpp
    TestCard.cpp
    TestDeck.cpp
    TestGame.cpp
    card.cpp
    deck.cpp
    game.cpp
)

# Include directories
target_include_directories(CardGameConsole PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${JSON_INCLUDE_DIR})
target_include_directories(CardGameGUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${JSON_INCLUDE_DIR})
target_include_directories(CardGameTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CATCH_INCLUDE_DIR} ${JSON_INCLUDE_DIR})

# Link against Qt for the GUI version
target_link_libraries(CardGameGUI PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

set_target_properties(CardGameGUI PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# Copy cardData.json to the build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cardData.json ${CMAKE_CURRENT_BINARY_DIR}/cardData.json COPYONLY)

# Add a custom target to run the tests
add_custom_target(run_tests
    COMMAND ${CMAKE_COMMAND} -E echo "Running tests..."
    COMMAND CardGameTests
    DEPENDS CardGameTests
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Add the test
add_test(NAME CardGameTests COMMAND CardGameTests)