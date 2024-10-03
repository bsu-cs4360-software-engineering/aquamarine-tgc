cmake_minimum_required(VERSION 3.14)
project(CardGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# Add your main game executable
add_executable(CardGame 
    main.cpp
    card.cpp
    deck.cpp
    game.cpp
)

# Add the test executable with a new name
add_executable(CardGameTestsNew 
    TestMain.cpp
    TestCard.cpp
    TestDeck.cpp
    TestGame.cpp
    card.cpp
    deck.cpp
    game.cpp
)

# Link against Catch2 and nlohmann_json
target_link_libraries(CardGame PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(CardGameTestsNew PRIVATE Catch2::Catch2WithMain nlohmann_json::nlohmann_json)

# Include directories
target_include_directories(CardGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(CardGameTestsNew PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Copy cardData.json to the build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cardData.json ${CMAKE_CURRENT_BINARY_DIR}/cardData.json COPYONLY)

# Add a custom target to run the tests
add_custom_target(run_tests
    COMMAND ${CMAKE_COMMAND} -E echo "Running tests..."
    COMMAND CardGameTestsNew
    DEPENDS CardGameTestsNew
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Add the test
add_test(NAME CardGameTestsNew COMMAND CardGameTestsNew)