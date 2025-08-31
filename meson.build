project('Pong', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

public_inc = include_directories('include')

lib_sources = files(
    'src/Log.cpp',
    'src/Vec2.cpp',
    'src/Ball.cpp',
    'src/Paddle.cpp',
    'src/Renderer.cpp',
    'src/GameBoundary.cpp',
    'src/Game.cpp',
    'src/GameInput.cpp',
    'src/CollisionBox.cpp',
)

test_sources = files(
    'test/CollisionBoxTests.cpp',
    'test/Vec2Tests.cpp',
    'test/PaddleTests.cpp',
    'test/GameBoundaryTests.cpp',
    'test/BallTests.cpp',
)

exec_sources = files(
    'src/main.cpp',
)

lib_dependencies = [
    dependency('spdlog', fallback : ['spdlog', 'spdlog_dep']),
    dependency('sdl2', version : '>=2.0.10', fallback : ['sdl2', 'sdl2_dep'])
]

test_dependencies = [
    dependency('gtest', fallback : ['gtest', 'gtest_dep']),
    dependency('gtest_main', fallback : ['gtest', 'gtest_main_dep'])
]

libs = static_library('PongLib',
                      lib_sources,
                      include_directories : public_inc,
                      dependencies : lib_dependencies,
)

tests = executable(
    'Tests',
    test_sources,
    dependencies : test_dependencies,
    include_directories : public_inc,
    link_with : libs,
)

executable('Pong',
           [
               lib_sources,
               exec_sources,
           ],
           install : true,
           include_directories : public_inc,
           dependencies : lib_dependencies,
           link_with : libs,
)

test('Tests', tests)
