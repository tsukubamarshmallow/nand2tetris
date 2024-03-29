// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen
// by writing 'black' in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen by writing
// 'white' in every pixel;
// the screen should remain fully clear as long as no key is pressed.

//// Replace this comment with your code.
// sumを0で初期化する
    @i
    M = 0
    @SCREEN
    D = M
    @p
    M = D
(LOOP)
    @i
    D = M
    @p
    M = M + D // *p = *P + 1
    A = M
    
    @END
    D;JEQ // D == 0であればエンドまでジャンプする
    @i
    M = M + 1 // i++
    @LOOP
    0;JMP // LOOPまでジャンプする
(END)
    @sum
    D = M
    @R2
    M = D
    @END
    0;JMP