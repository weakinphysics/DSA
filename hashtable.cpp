#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

/*
    This is a simple hash table that puts stuff into cubby holes,
    the dimension of the column space is generally smaller than the input space
    Okay, so we resize the above table only when the need arises. 

    For caching, we need to design a data structure that can fit within the CPU L1 cache
    to enable hot storage. For cold storage, no one gives a damn.

*/

