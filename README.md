<h1>Implementing generic data structures in pure C</h1>
<h2>The philosophy is:</h2>
<ul>
<li>All dynamic data structures are of type byte* (typedefed char) - helps to unify all the functionality and maintain generic types.</li>
<li>Interaction with these data structures must happen only with given functionality.</li>
<li>Getting elements of given data structure happens either with subscription [] operator or with it's %NAME%_getitem() function, which checks for out of bounds.</li>
<li>All memory interaction happens via memory.h module functionality.</li>
<li>All data structures are based on dynamic array.</li>
<li>In every module, data structure's functions are named: %struct name in uppercase%_%method functionality in lowercase%</li>
<li><p>Before every data structure lies a 'header' struct which contains main information about the array.
This header leads to O(1) time for getting structure's length, capacity, element size and other crucial parameters.</p></li>
</ul>
<h2>Note:</h2>
Code like this:

```
DA_append(array, 10)
```

will not work, because of the internal memcpy mechnism that any insertion invokes. Therefore, (for now) only further code is valid:
```
int elem = 10;
DA_append(array, elem);
```
<h2>You are free to extend this interface, presuming you will follow the principles above.</h2>
