cmake_minimum_required(VERSION 3.21)
project(APVS LANGUAGES CXX)

# APVS uses C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/Core/Resources.hpp"
    "src/Core/Resources.cpp"
    "src/Core/Application.hpp"
    "src/Core/Application.cpp"
    "src/State/Base/State.hpp"
    "src/State/Base/State.cpp"
    "src/State/Base/StateMachine.hpp"
    "src/State/Base/StateMachine.cpp"
    "src/State/CheckoutState.hpp"
    "src/State/CheckoutState.cpp"
    "src/State/CurrencySelectionState.hpp"
    "src/State/CurrencySelectionState.cpp"
    "src/State/CheckoutState.hpp"
    "src/State/CheckoutState.cpp"
    "src/State/AvailablePrescriptionState.hpp"
    "src/State/AvailablePrescriptionState.cpp"
    "src/State/PatientInfoState.hpp"
    "src/State/PatientInfoState.cpp"
    "src/State/DLInfoState.hpp"
    "src/State/DLInfoState.cpp"
    "src/State/IntroState.hpp"
    "src/State/IntroState.cpp"
    "src/UI/Interface/Elements/_base/UIElement.hpp"
    "src/UI/Interface/Elements/Button/Base/Button.hpp"
    "src/UI/Interface/Elements/Button/CircleButton.cpp"
    "src/UI/Interface/Elements/Button/RectButton.cpp"
    "src/UI/Interface/Elements/Button/StadiumButton.cpp"
    "src/UI/Interface/Elements/Textbox/Textbox.hpp"
    "src/UI/Interface/Elements/Textbox/Textbox.cpp"
    "src/UI/Interface/Elements/Toggle/Toggle.hpp"
    "src/UI/Interface/Elements/Toggle/Toggle.cpp"
    "src/UI/Interface/Shapes/ConvexShape.hpp"
    "src/UI/Interface/Shapes/ConvexShape.cpp"
    "src/UI/Interface/Shapes/StadiumShape.hpp"
    "src/UI/Interface/Shapes/StadiumShape.cpp"
    )
add_executable(APVS ${SOURCE_FILES})

target_link_libraries(APVS PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

target_compile_features(APVS PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET APVS POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:APVS> $<TARGET_FILE_DIR:APVS> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS APVS
        CONFIGURATIONS Debug
        RUNTIME DESTINATION)

