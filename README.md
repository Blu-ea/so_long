# so_long
== This is my repo for the so_long Project from school 42 ==

For now there is juste a parsing of the map and it's rendering

## Rules

### Parsing of the map

- The different blocs are:
    - '1' -> Wall
    - '0' -> Empty
    - 'P' -> Player's starting position
    - 'C' -> Colectible
    - 'E' -> Exit
  
- The map need to be rectangular with closed sides with no space between each blocs
- There has to be at least one of 'P', 'C' and 'E'
    - exemple:
                    
          1111111111111111111111111111111111
          1E0000000000000C00000C0000000000C1
          1010010100100000101001000000010101
          1010010010101010001001000000010101
          1P0000000C00C0000000000000000000E1
          1111111111111111111111111111111111
