
// Minimalne drzewoco�zmieni�am

// Algorytm Kruskala
=======
// Minimalne drzewo rozpinaj¹ce
// Algorytm Kruskala - bardzo mądry pan
// Data: 6.04.2014
// (C)2014 mgr Jerzy Wa³aszek



//--------------------------------





// Definicja obiektu kolejki priorytetowej
//----------------------------------------
type
  Edge = record
    v1,v2  : integer;             // Wierzcho³ki krawêdzi
    weight : integer;             // Waga krawêdzi
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

// Definicja obiektu struktury zbiorów roz³¹cznych
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

// Definicja obiektu minimalnego drzewa rozpinaj¹cego
//---------------------------------------------------
  PTNode = ^TNode;
  TNode = record
    next   : PTNode;
    v      : integer;
    weight : integer;
  end;

  MSTree = object
    private
      A : array of PTNode;        // Tablica list s¹siedztwa
      Alen : integer;             // Liczba komórek w tablicy
      weight : integer;           // Waga ca³ego drzewa
    public
      constructor init(n : integer);
      destructor  destroy;
      procedure   addEdge(e : Edge);
      procedure   print;
<<<<<<< HEAD
  
=======
  end;
>>>>>>> ea8b1691c1e97528676e8fb328fa50d18b4ec1ae
