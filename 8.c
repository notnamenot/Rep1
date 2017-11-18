program spojgraf;

// Typy dla dynamicznej tablicy list s¹siedztwa oraz stosu
type
  PslistEl = ^slistEl;
  slistEl =  record
    next  : PslistEl;
    v     : integer;
  end;

TList = array of PslistEl;

// Definicja typu obiektowego stack
//---------------------------------
stack = object
  private
    S : PslistEl;  // lista przechowuj¹ca stos

  public
    constructor init;
    destructor destroy;
    function   empty : boolean;
    function   top : integer;
    procedure  push(v : integer);
    procedure  pop;
end;

// Konstruktor
//------------
constructor stack.init;
begin
  S := nil;
end;

// Destruktor
//-----------

destructor stack.destroy;
begin
  while S <> nil do pop;
end;

// Sprawdza, czy stos jest pusty
//------------------------------
function stack.empty : boolean;
begin
  if S = nil then empty := true else empty := false;
end;

// Zwraca liczbê ze szczytu stosu
//----------------------------------
function stack.top : integer;
begin
  top := S^.v;
end;

// Umieszcza dane na stosie
//-------------------------
procedure stack.push(v : integer);
var
  e : PslistEl;
begin
  new(e);
  e^.v := v;
  e^.next := S;
  S := e;
end;

// Usuwa dane ze stosu
//--------------------
procedure stack.pop;
var
  e :PslistEl;
begin
  if S <> NIL then
  begin
    e := S;
    S := S^.next;
    dispose(e);
  end;
end;

// **********************
// *** Program g³ówny ***
// **********************

var
  n,m      : integer;          // Liczba wierzcho³ków i krawêdzi
  A        : TList;            // Tablica list s¹siedztwa grafu
  visited  : array of boolean; // Tablica odwiedzin
  S        : stack;            // Stos
  i,v,u,vc : integer;
  p,r      : PslistEl;