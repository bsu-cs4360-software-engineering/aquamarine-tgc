cmake_minimum_required(VERSION 3.14)
   project(CardGame)

   set(CMAKE_CXX_STANDARD 17)
   set(CMAKE_CXX_STANDARD_REQUIRED ON)
   set(CMAKE_AUTOMOC ON)
   set(CMAKE_AUTORCC ON)
   set(CMAKE_AUTOUIC ON)

   include(FetchContent)

   # Fetch nlohmann_json
   FetchContent_Declare(
       json
       URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
   )
   FetchContent_MakeAvailable(json)

   # Fetch and make available Catch2
   FetchContent_Declare(
       Catch2
       GIT_REPOSITORY https://github.com/catchorg/Catch2.git
       GIT_TAG v3.3.2
   )
   FetchContent_MakeAvailable(Catch2)

   # Find Qt6
   find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

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

   # Link against nlohmann_json
   target_link_libraries(CardGameConsole PRIVATE nlohmann_json::nlohmann_json)
   target_link_libraries(CardGameGUI PRIVATE nlohmann_json::nlohmann_json Qt6::Core Qt6::Gui Qt6::Widgets)
   target_link_libraries(CardGameTests PRIVATE Catch2::Catch2WithMain nlohmann_json::nlohmann_json)

   # Include directories
   target_include_directories(CardGameConsole PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
   target_include_directories(CardGameGUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
   target_include_directories(CardGameTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

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