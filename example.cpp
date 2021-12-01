

int n = 10;
// may be scan(n)
// scan(a, b, ...); is same as cin >> a >> b >> ...;
int[10] a;
// you can use only numbers literal as size of array


def qsort(int l, int r, int i, int j) -> void {
  // I have to use i, j in parameters, because of 2nd problems from readme.md
  int mid = a[(l + r) /2];
  i = l;
  j = r;
  while (i < j) {
    while (a[i] < mid) {
      i += 1; // ++ and -- are not realised yet
    }
    while (a[j] > mid) {
      j -= 1;
    }
    if (i <= j) {
      int e = a[i];
      a[i] = a[j];
      a[j] = e;
      j -= 1;
      i += 1;
    }
  }
  if (l < j) {
    qsort(l, j, 0, 0);
  }
  if (i < r) {
    qsort(i, r, 0, 0);
  }
}

def bubble_sort(int l, int r) -> void {
  int i = l;
  for (int i = l; i <= r; i += 1) {
    for (int j = i+1; j <= r; j += 1) {
      if (a[i] > a[j]) {
        int e = a[i];
        a[i] = a[j];
        a[j] = e;
      }
    }
  }
}

a[0] = 9;
a[1] = 3;
a[2] = 4;
a[3] = 1;
a[4] = 5;
a[5] = 7;
a[6] = 0;
a[7] = 2;
a[8] = 8;
a[9] = 6;
// you can you scan(a), which use cin >> a[0] >> a[1] >> ... >> a[size-1];

print("before sorting: ", a);
qsort(0, n-1, 0, 0);
//bubble_sort(0, n-1);
print("after sorting:  ", a);


string[3] s;
s[0] = "string";
s[1] = "works";
s[2] = "too";
string res = "";
for (int i = 0; i < 3; i += 1) {
  res += s[i] + " ";
}
print(res);