This project demonstrates how to test a C library with GoogleTest and Bazel.

## Quickstart

- [Install Bazel](https://docs.bazel.build/versions/master/install.html)

- Run the following command:
```
bazel test --test_output=all //tests:CalcTests
```

## Debugging

If you'd like to debug your library, build the tests with the `-c dbg` flag:
```
bazel build //tests:CalcTests -c dbg
```

Then you can debug with GDB:
```
gdb bazel-bin/tests/CalcTests
```

## Additional VSCode configuration

The existing `launch.json` and `tasks.json` configs in `.vscode/` should enable traditional debugging of the entire test suite. Just set your breakpoints and press `F5`.

The [C++ TestMate](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter) extension enables a nice interface for running, viewing, and debugging individual test cases, but requires some additional configuration for Bazel compatibility.

If using that extension, you'll need to edit the `advancedExecutables` setting to contain the following:
```
    "testMate.cpp.test.advancedExecutables": [
      {
        "pattern": "{bazel-bin,build,Build,BUILD,out,Out,OUT}/**/*{test,Test,TEST}*",
        "sourceFileMap": { "/proc/self/cwd": "${workspaceFolder}" },
      }
    ]
```

Ideally, editing `advancedExecutables` should not be necessary. You should only need to add the `bazel-bin` pattern to the `testMate.cpp.test.executables` setting, and the `sourceFileMap` setting should have been picked-up from `launch.json`.

Once configured, you should be able to debug individual test cases by clicking on the debug icon in the `Testing` sidebar.