# CmdTimer - Simple Console Timer

CmdTimer is a header-only utility that provides a lightweight timer for small console tools and utilities.  
It is designed to be easy to drop into any project where you want quick, readable timing for a scope, a phase, or a full run — with minimal code and zero third-party dependencies.

### Compatibility and Dependencies
- C++11 Standard and above
- Standard Template Library (STL)
- Uses `std::chrono` for timing

### OS Support
- Windows
- Linux
- macOS

## Usage

Copy `CmdTimer.h` to your project and include the file.

CmdTimer is intended to be dead-simple:
- Start a timer (optionally with a label)
- Do work
- Stop the timer and print the elapsed time

- ## Example code - simple

```cpp
#include <iostream>
#include "CmdTimer.h"

int main()
{
    timer::start("Processing");
    // Do work...
    timer::stop(); // prints elapsed time
    return 0;
}
```

## CmdTimer output examples

| Duration range | Example output |
| --- | --- |
| >= 1 hour | `1 h 37 m 11 s` |
| >= 1 minute and < 1 hour | `10 m 2 s` |
| >= 1 second and < 1 minute | `0 m 5 s` |
| >= 1 millisecond and < 1 second | `120 milliseconds` |
| < 1 millisecond | `350 microseconds` |

## License

This software is released under the MIT License terms.
