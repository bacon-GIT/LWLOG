# NO REQUIREMENTS
## Just add the header file to your project and 
```#include "Log.h"```

And initialize the logger as a global variable to avoid having to define it within every function:

```Log::Logger mylogger(<LOG FILE NAME>, <COUT OUTPUT>);```

I got sick of using bloated logging libraries when I only needed to do two things, tell me what went wrong and when. Making this more verbose and easy to use as I go.