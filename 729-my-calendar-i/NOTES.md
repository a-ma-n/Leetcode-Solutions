​
a.start<=b.start && a.end>=b.start
----
-----
b
b.start<=a.start && b.end>=a.start
-----
-----
d(no intersection) - true
a.end<b.start
----
------
e(no intersection) - true
a.start>b.end
------
-----