achange



program sets;

// Definicja struktury zbioru

type
  s_set =  record
    vmin  : integer;
    nmax  : integer;
    T     : array of byte;
  end;

// Procedura usuwa wszystkie elementy ze zbioru
//---------------------------------------------
procedure s_clear(var A : s_set);
var
  i : integer;
begin
  for i := 0 to A.nmax do A.T[i] := 0; // Zerujemy tablicê
end;

// Procedura tworzy pusty zbiór
//-----------------------------
procedure s_create(var A : s_set; vmin, vmax : integer);
begin
  A.vmin := vmin;                 // Wype³niamy strukturê A
  A.nmax := vmax - vmin;
  SetLength(A.T,A.nmax + 1);      // Tworzymy tablicê dynamiczn¹ na elementy
  s_clear(A);                     // Zbiór zerujemy
end;

// Procedura oblicza sumê zbiorów A i B.
// Wynik umieszcza w zbiorze C
//--------------------------------------
procedure s_union(var A,B,C : s_set);
var
  i : integer;
begin
  for i := 0 to A.nmax do C.T[i] := A.T[i] or B.T[i];
end;

// Procedura oblicza iloczyn zbiorów A i B.
// Wynik umieszcza w zbiorze C
//-----------------------------------------
procedure s_intersection(var A,B,C : s_set);
var
  i : integer;
begin
  for i := 0 to A.nmax do C.T[i] := A.T[i] and B.T[i];
end;

// Procedura oblicza ró¿nicê zbiorów A i B.
// Wynik umieszcza w zbiorze C
//-----------------------------------------
procedure s_difference(var A,B,C : s_set);
var
  i : integer;
begin
  for i := 0 to A.nmax do C.T[i] := A.T[i] and not B.T[i];
end;

// Procedura oblicza dope³nienie zbioru A.
// Wynik umieszcza w zbiorze C
//----------------------------------------
procedure s_complement(var A,C : s_set);
var
  i : integer;
begin
  for i := 0 to A.nmax do C.T[i] := 1 and not A.T[i];
end;

// Funkcja sprawdza, czy zbiór A jest podzbiorem zbioru B.
// true  - tak
// false - nie
//--------------------------------------------------------
function s_subset(var A,B : s_set) : boolean;
var
  i : integer;
begin
  for i := 0 to A.nmax do
    if (A.T[i] = 1) and (B.T[i] = 0) then Exit(false);
  s_subset := true;
end;

// Funkcja oblicza liczbê elementów w zbiorze A
//---------------------------------------------
function s_size(var A : s_set) : integer;
var
  i,s : integer;
begin
  s := 0;                         // Zerujemy sumê
  for i := 0 to A.nmax do s := s + A.T[i]; // Sumujemy komórki
  s_size := s;
end;

// Funkcja sprawdza, czy zbiór jest pusty.
// true  - tak, zbiór jest pusty
// false - nie, zbiór nie jest pusty
//----------------------------------------
function s_empty(var A : s_set) : boolean;
begin
  s_empty := s_size(A) = 0;
end;

// Procedura dodaje do zbioru element
//-----------------------------------
procedure s_add(var A : s_set; x : integer);
begin
  A.T[x - A.vmin] := 1;
end;

// Procedura usuwa ze zbioru element
//----------------------------------
procedure s_remove(var A : s_set; x : integer);
begin
  A.T[x - A.vmin] := 0;
end;

// Funkcja bada obecnoœæ elementu w zbiorze.
// true  - element jest w zbiorze
// false - elementu nie ma w zbiorze
//------------------------------------------
function s_isin(var A : s_set; x : integer) : boolean;
begin
  s_isin := A.T[x - A.vmin] = 1;
end;

// Procedura wyœwietla zawartoœæ zbioru
//-------------------------------------
procedure s_print(var A : s_set);
var
   i : integer;
begin
  for i := 0 to A.nmax do
    if A.T[i] = 1 then write(i+A.vmin:3);
end;

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************

var
  A,B,C : s_set;
  i,x   : integer;

begin
  randomize;                      // Inicjujemy generator pseudolosowy

  // Tworzymy puste zbiory o zakresie elementów od -5 do 20

  s_create(A,-5,20);
  s_create(B,-5,20);
  s_create(C,-5,20);

  // Do zbioru A dodajemy 10 losowych elementów

  for i := 1 to 10 do s_add(A,-5 + random(26));

  // Do zbioru B dodajemy 25 losowych elementów

  for i := 1 to 15 do s_add(B,-5 + random(26));

  // Wyœwietlamy je

  write('A ='); s_print(A); writeln;
  writeln('SIZE OF A IS ',s_size(A));
  writeln;
  write('B ='); s_print(B); writeln;
  writeln('SIZE OF B IS ',s_size(B));

  // Suma zbiorów

  writeln;
  write('UNION OF A AND B IS');
  s_union(A,B,C);
  s_print(C); writeln;
  writeln('SIZE OF UNION IS ',s_size(C));

  // Iloczyn zbiorów

  writeln;
  write('INTERSECTION OF A AND B IS');
  s_intersection(A,B,C);
  s_print(C); writeln;
  writeln('SIZE OF INTERSECTION IS ',s_size(C));

  // Ró¿nica zbiorów

  writeln;
  write('DIFFERENCE OF A AND B IS');
  s_difference(A,B,C);
  s_print(C); writeln;
  writeln('SIZE OF DIFFERENCE IS ',s_size(C));

  // Dope³nienie zbioru

  writeln;
  write('COMPLEMENT OF A IS');
  s_complement(A,C);
  s_print(C); writeln;
  writeln('SIZE OF COMPLEMENT IS ',s_size(C));
