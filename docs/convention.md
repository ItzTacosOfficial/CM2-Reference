## FAKT Software Naming Convention

| Symbol | Meaning                      |
|--------|------------------------------|
| (P)    | Matches `[A-Z][A-Z,0-9]*`    |
| (p)    | Matches `[A-Z][a-z,0-9]*`    |
| (h)    | Hungarian notation prefix    |
| (e)    | Enum name (may be shortened) |

| Identifier                     | Convention   |
|--------------------------------|--------------|
| Static function                | StaticMyFunc |
| Global exposed function        | (p)MyFunc    |
| Global implementation function | _(p)MyFunc   |
| Member function                | MyFunc       |
| Static member function         | StaticMyFunc |
| Class                          | (P)MyClass   |
| Class template                 | (P)TMyClass  |
| Scoped struct                  | MyStruct     |
| Global struct                  | MYSTRUCT     |
| Enum                           | MY_ENUM      |
| Macro                          | MY_MACRO     |
| Enumerator                     | (e)_VALUE    |
| Member[^1]                     | m_(h)MyVar   |
| Static member                  | ms_(h)MyVar  |
| Global variable                | g_(h)MyVar   |
| Static variable                | s_(h)MyVar   |
| Local variable                 | (h)MyVar     |

[^1]: Not applied in the reference for convenience.
