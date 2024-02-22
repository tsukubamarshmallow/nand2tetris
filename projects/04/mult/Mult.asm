// sumを0で初期化する
    @i
    M = 1
    @sum
    M = 0
(LOOP)
    @R0
    D = M // D = R0
    @sum
    M = M + D //sum += R0
    @R1
    D = M  // D = R1
    @i
    D = D - M // D = R1 - i
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
