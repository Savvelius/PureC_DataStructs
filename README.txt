All dynamic data structures are of type byte* - helps to unify all the functionality and maintain generic types.
Interaction with these data structures must happen only with given functionality.
Getting elements of given data structure happens only with it's %NAME%_getitem() function.
All memory interaction happens via memory.h module functionality.

All data structures are based on dynamic array.
In every module, data structure's functions are named: %struct name in uppercase%_%method functionality in lowercase%
Before every data structure lies a 'header' struct which contains main information about the array.
This header leads to O(1) time for getting structure's length, capacity, element size and other crucial parameters.

You are free to extend this interface, presuming you will follow the principles above.