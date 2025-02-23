sources += files('argument.cpp')

static_lib = static_library('argument', sources, include_directories : inc, install : true)
shared_lib = shared_library('argument', sources, include_directories : inc, install : true)

test_sources = files('argument.test.cpp', 'argument.cpp')

doctest_dep = dependency('doctest', fallback : ['doctest', 'doctest_dep'])

test_executable = executable(
    'test_arguments',
    test_sources,
    include_directories : inc,
    dependencies : doctest_dep,
    link_with : static_lib
)

test('test_arguments', test_executable)