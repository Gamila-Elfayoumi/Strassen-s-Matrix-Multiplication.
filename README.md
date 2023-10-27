# Strassen-s-Matrix-Multiplication.
Due to the strassen's algorithm we minimise the complexity of the matrix multiplication from O(n^3) to O(n^2,8).
This is because we decrease the number of multiplication terms.
Matrix Synboles:
A[[a.b],[c,d]]
B[[e,f],[g,h]]
result[[C11,C12],[C21,C22]]
Equation used in code:
M1=(a+d)(e+h)
M2=d(g-e)
M3=h(a+b)
M4=(b-d)(g+h)
M5=a(f-h)
M6=e(c+d)
M7=(a-c)(e+f)
let:
a --> A11
b --> A12
c --> A21
d --> A22
e --> B11
f --> B12
g --> B21
h --> B22
Result matrix equation:
C11 = M1+M2-M3+M4
C12 = M5+M3
C21 = M6+M2
C22 = M5+M1-M6-M7
