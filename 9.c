program maxflow;

// Definicja typu elementów listy
//-------------------------------
type
  PslistEl = ^slistEl;
  slistEl = record
    next  : PslistEl;
    data  : integer;
  end;

// Definicja typu obiektowego queue
//---------------------------------
  queue = object
    private
      head : PslistEl;
      tail : PslistEl;

    public
      constructor init;
      destructor destroy;
      function empty : boolean;
      function front : integer;
      procedure push(v : integer);
      procedure pop;
  end;

//---------------------
// Metody obiektu queue
//---------------------

// Konstruktor - tworzy pust¹ listê
//---------------------------------
constructor queue.init;
begin
  head := nil;
  tail := nil;
end;

// Destruktor - usuwa listê z pamiêci
//-----------------------------------
destructor queue.destroy;
begin
  while not empty do pop;
end;

// Sprawdza, czy kolejka jest pusta
//---------------------------------
function queue.empty : boolean;
begin
  if head = nil then empty := true
  else               empty := false;
end;

// Zwraca pocz¹tek kolejki.
// Wartoœæ specjalna to -MAXINT
//-----------------------------
function queue.front : integer;
begin
  if head = nil then front := -MAXINT
  else               front := head^.data;
end;

// Zapisuje do kolejki
//--------------------
procedure queue.push(v : integer);
var
  p : PslistEl;
begin
  new(p);
  p^.next := nil;
  p^.data := v;
  if tail = nil then head := p
  else tail^.next := p;
  tail := p;
end;

// Usuwa z kolejki
//----------------
procedure queue.pop;
var
  p : PslistEl;
begin
  if head <> nil then
  begin
    p := head;
    head := head^.next;
    if head = nil then tail := nil;
    dispose(p);
  end;
end;

//---------------
// Program g³ówny
//---------------

var
  Q : queue;                      // Kolejka
  C : array of array of integer;  // Macierz przepustowoœci
  F : array of array of integer;  // Macierz przep³ywów netto
  P : array of integer;           // Tablica poprzedników
  CFP : array of integer;         // Tablica przepustowoœci rezydualnych
  n,m,s,t,fmax,cp,x,y,i,j : integer;  // Zmienne proste algorytmu
  esc : boolean;                  // Do wychodzenia z zagnie¿d¿onych pêtli

begin
  Q.init;                         // Inicjujemy kolejkê

  // Ze standardowego wejœcia odczytujemy
  // n - liczbê wierzcho³ków w grafie sieci
  // m - liczbê krawêdzi

  read(n,m);

  // Tworzymy dynamicznie macierze:
  // C - przepustowoœci krawêdzi
  // F - przep³ywy w krawêdziach

  SetLength(C,n); SetLength(F,n);
  for i := 0 to n - 1 do
  begin
    SetLength(C[i],n);
    SetLength(F[i],n);
  end;
