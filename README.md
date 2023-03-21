# NO REQUIREMENTS
## Just add the header file to your project and 
```#include "Log.h"```

And initialize the logger as a global variable to avoid having to define it within every function:

```Log::Logger mylogger(<LOG FILE NAME>, <COUT OUTPUT>);```

And remember to ```mylogger.CloseLogger();``` to close the filestream. This was originally the destructor but that caused a wholly unnecessary amount of file operations.

```
Log Levels:
    0   -   NONE
    1   -   DEBUG
    2   -   INFO
    3   -   WARM
    4   -   ERROR
    5   -   CRITICAL
```

I got sick of using bloated logging libraries when I only needed to do two things, tell me what went wrong and when. Making this more verbose and easy to use as I go.