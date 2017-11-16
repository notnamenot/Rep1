// Minimalne drzewoco�zmieni�am
// Algorytm Kruskala
// Data: 6.04.2014
// (C)2014 mgr Jerzy Wa�aszek
//--------------------------------

// Definicja obiektu kolejki priorytetowej
//----------------------------------------
type
  Edge = record
    v1,v2  : integer;             // Wierzcho�ki kraw�dzi
    weight : integer;             // Waga kraw�dzi
  end;

  Queue = object
    private
      Heap : array of Edge;
      hpos : integer;
    public
      constructor init(n : integer);
      destructor  destroy;
      function    front : Edge;
      procedure   push(e : Edge);
      procedure   pop;
  end;

// Definicja obiektu struktury zbior�w roz��cznych
//------------------------------------------------
  DSNode = record
    up   : integer;
    rank : integer;
  end;

  DSStruct = object
    private
      Z : array of DSNode;
    public
      constructor init(n : integer);
      destructor  destroy;
      procedure   MakeSet(v : integer);
      function    FindSet(v : integer) : integer;
      procedure   UnionSets(e : Edge);
  end;

// Definicja obiektu minimalnego drzewa rozpinaj�cego
//---------------------------------------------------
  PTNode = ^TNode;
  TNode = record
    next   : PTNode;
    v      : integer;
    weight : integer;
  end;

  MSTree = object
    private
      A : array of PTNode;        // Tablica list s�siedztwa
      Alen : integer;             // Liczba kom�rek w tablicy
      weight : integer;           // Waga ca�ego drzewa
    public
      constructor init(n : integer);
      destructor  destroy;
      procedure   addEdge(e : Edge);
      procedure   print;
  