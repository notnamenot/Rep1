program eulercp;


// Typy dla dynamicznej tablicy list s�siedztwa oraz stosu
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
    S : PslistEl;  // lista przechowuj�ca stos

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

// Zwraca liczb� ze szczytu stosu
//----------------------------------
function stack.top : integer;
begin
  top := S^.v;
end;