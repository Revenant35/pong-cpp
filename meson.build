project('Pong', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

spd = dependency('spdlog', fallback : ['spdlog', 'spdlog_dep'])
sdl = dependency('sdl2', version : '>=2.0.10', fallback : ['sdl2', 'sdl2_dep'])
#gtest = dependency('gtest', fallback : ['gtest', 'gtest_dep'])
#gtest_main = dependency('gtest_main', fallback : ['gtest', 'gtest_main_dep'])

public_inc = include_directories('include')

sources = files(
    'src/Log.cpp',
    'src/Window.cpp',
    'src/Vec2.cpp',
    'src/Ball.cpp',
    'src/Paddle.cpp',
    'src/Renderer.cpp',
    'src/GameBoundary.cpp',
    'src/Game.cpp',
    'src/GameInput.cpp',
    'src/main.cpp',
)

Pong = executable('Pong',
                  sources,
                  install : true,
                  include_directories : public_inc,
                  dependencies : [
                      spd,
                      sdl
                  ]
)