

// Minimalne drzewoco�zmieni�am

=======
// Minimalne drzewocoœzmieni³am

=======
//Minimalne drzewocoœzmieni³am

// Algorytm Kruskala
=======

// Minimalne drzewo rozpinajÂ¹ce
// Algorytm Kruskala - bardzo mÄ…dry pan
// Data: 6.04.2014

// (C)2014 mgr Jerzy Wa³aszek



//--------------------------------





=======


// (C)2014 mgr Jerzy WaÂ³aszek
//--------------------------------

  
  

// Definicja obiektu kolejki priorytetowej
//----------------------------------------
type
  Edge = record

  
  
  v1,v2  : integer;             // WierzchoÂ³ki krawÃªdzi
  //
    weight : integer;             // Waga krawÃªdzi
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

// Definicja obiektu struktury zbiorÃ³w rozÂ³Â¹cznych
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

// Definicja obiektu minimalnego drzewa rozpinajÂ¹cego
//---------------------------------------------------
  PTNode = ^TNode;
  TNode = record
    next   : PTNode;
    v      : integer;
    weight : integer;
  end;

  MSTree = object
    private
      A : array of PTNode;        // Tablica list sÂ¹siedztwa
      Alen : integer;             // Liczba komÃ³rek w tablicy
      weight : integer;           // Waga caÂ³ego drzewa
    public
      constructor init(n : integer);
      destructor  destroy;
      procedure   addEdge(e : Edge);
      procedure   print;

  
=======
  end;

