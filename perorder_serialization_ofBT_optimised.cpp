#include <bits/stdc++.h>
using namespace std;

/*
serializationm of the form 9,#,67,##...
*/

bool isValidSerialization(string preorder) {
   int cnt = 1;
   bool lastd = false;
   for (char c : preorder) {
       if (isdigit(c)) {
           if (lastd)
               continue;
           if (!cnt)
               return false;
           cnt++;
           lastd = true;
       }
       else {
           if (c == '#')
               cnt--;
           lastd = false;
       }
   }
   return cnt == 0;
}
