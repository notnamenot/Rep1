Const MAXINT = 2147483647


' Definicja typu elementów listy
'-------------------------------
Type slistEl
  Next As slistEl Ptr
  Data As Integer
End Type

' Definicja typu obiektowego queue
'---------------------------------
Type queue
  Private:
    head As slistEl Ptr
    tail As slistEl Ptr

  Public:
    Declare Constructor()
    Declare Destructor()
    Declare Function empty() As Integer
    Declare Function front As Integer
    Declare Sub push(Byval v As Integer)
    Declare Sub pop()
End Type

'---------------------
' Metody obiektu queue
'---------------------

' Konstruktor - tworzy pust¹ listê
'---------------------------------
Constructor queue()
  head = 0
  tail = 0
End Constructor

' Destruktor - usuwa listê z pamiêci
'-----------------------------------
Destructor queue()
  While empty = 0: pop: Wend
End Destructor

' Sprawdza, czy kolejka jest pusta
'---------------------------------
Function queue.empty() As Integer
  If head = 0 Then Return 1
  Return 0
End Function

' Zwraca pocz¹tek kolejki.
' Wartoœæ specjalna to -MAXINT
'-----------------------------
Function queue.front() As Integer
  If head = 0 Then
    front = -MAXINT
  Else
    front = head->Data
  End If
End Function

' Zapisuje do kolejki
'--------------------
Sub queue.push(Byval v As Integer)
  Dim p As slistEl Ptr
  p = New slistEl
  p->Next = 0
  p->Data = v
  If tail = 0 Then
    head = p
  Else
    tail->Next = p
  End If
  tail = p
End Sub

' Usuwa z kolejki
'----------------
Sub queue.pop()
  Dim p As slistEl Ptr
  If head Then
    p = head
    head = head->Next
    If head = 0 Then tail = 0
    Delete p
  End If
End Sub