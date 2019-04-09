; 48710202 (Stuart Green)
;
    bits 16
    org 100h                ; Start program at offset 100
;
; This program:
;       a. changes the screen and text colour (yellow on blue);
;       b. positions the cursor and outputs a prompt;
;       c. accepts one character input from the user (validates for A-E only);
;       d. and outputs enlarged version of the input letter as a pattern.
;
;
;------ Jump past data declarations ---------------------------------------------
    jmp main                ; Jump to main program
;
;
;------ Data declarations -------------------------------------------------------
;
txt_prompt: db 'Enter a character (A-E only): $'
txt_err:    db 0dh, 0ah, 'The program only works for characters A-E... try again. $'
txt_crlf:   db 0dh, 0ah, '$'

pattern_a:  db 4h, 0Ah, 11h, 1Fh, 11h, 11h, 11h
pattern_b:  db 1Eh, 11h, 11h, 1Eh, 11h, 11h, 1Eh
pattern_c:  db 0Eh, 11h, 10h, 10h, 10h, 11h, 0Eh
pattern_d:  db 1Eh, 11h, 11h, 11h, 11h, 11h, 1Eh
pattern_e:  db 1Fh, 10h, 10h, 1Eh, 10h, 10h, 1Fh

char:       db 1
;
;
;------ Setup screen and cursor position ----------------------------------------
;
set_scrn:
    mov dx, 0000h           ; Position for cursor
    mov ah, 2h              ; "Set cursor position" function for INT 10h
    int 10h
    
    mov cx, 2000            ; Counter value
    mov bl, 1Eh             ; Colour values for background and text (yellow on blue)
    mov al, 20h             ; Blank character to be output
    mov ah, 9h              ; "Write character and attribute..." function for INT 10h
    int 10h
    
    mov dx, 0A00h           ; Position for cursor (row 10, col 0)
    mov ah, 2h              ; "Set cursor position" function for INT 10h
    int 10h
    ret
;
;
;------ Functions for displaying text -------------------------------------------
;
display:
    mov ah, 9h              ; "Display string" function for INT 21h
    int 21h
    ret

disp_prompt:
    mov dx, txt_prompt      ; Copy contents of txt_prompt to 'dx'
    call display
    ret

disp_err:
mov dx, txt_err             ; Copy contents of txt_err to 'dx'
call display
jmp terminate               ; Jump to terminate program

disp_crlf:
    mov dx, txt_crlf        ; Copy contents of txt_crlf to 'dx'
    call display
    ret
;
;
;------ Get user character input ------------------------------------------------
;
get_char:
mov ah, 1h                  ; "Character input" function for INT 21h (stored in 'al')
int 21h
mov [char], al              ; Copy contents of 'al' to space at address [char]
ret
;
;
;------ Validate that input is A-E ----------------------------------------------
;
validate:
    mov dl, 'A'             ; Copy character to 'dl' for comparison
    cmp [char], dl          ; Compare to input character
    jb disp_err             ; Display error if < A (41h)
    mov dl, 'E'
    cmp [char], dl
    ja disp_err             ; Display error if > E (45h)
    ret
;
;
;------ Set pattern for output based on input character -------------------------
;
set_pattern:
mov dl, 'A'                 ; Copy character to 'dl' for comparison
cmp [char], dl              ; Compare to input character
je set_a                    ; If equal, set pattern to A
mov dl, 'B'
cmp [char], dl
je set_b
mov dl, 'C'
cmp [char], dl
je set_c
mov dl, 'D'
cmp [char], dl
je set_d
mov dl, 'E'
cmp [char], dl
je set_e
;
;
;------ Functions for displaying enlarged character -----------------------------
;
set_a:
    mov si, pattern_a       ; Copy contents of pattern_a to 'si'
    ret

set_b:
    mov si, pattern_b       ; Copy contents of pattern_b to 'si'
    ret

set_c:
    mov si, pattern_c       ; Copy contents of pattern_c to 'si'
    ret

set_d:
    mov si, pattern_d       ; Copy contents of pattern_d to 'si'
    ret

set_e:
    mov si, pattern_e       ; Copy contents of pattern_e to 'si'
    ret

disp_char:
    mov cx, 7               ; Counter value for outer loop (for 7 lines of output)
    loop1:                  ; Start outer loop
        call disp_crlf
        mov bl, [si]        ; Copy contents of address to 'bl'
        mov ah, 2h          ; "Character output" function for INT 21h (stored in 'dl')
        push cx             ; Push counter value to stack for later use
        mov cx, 8           ; Counter value for the bits (8 in a byte)
        loop2:              ; Start inner loop
            rcl bl, 1h      ; Shift bits by rotate through carry left
            mov dl, 30h     ; Change to ASCII (number + '0')
            adc dl, 0h      ; Add with carry
            cmp dl, '0'     ; IF the value in 'dl' is 0
            jz then         ; jump to THEN
            mov dl, '$'     ; ELSE '$' will be output
            jmp continue    ; Jump past the THEN statement to continue function
            then:
                mov dl, 20h ; A blank space will be output if 'dl' is 0
            continue:
                int 21h
        loop loop2          ; End of inner loop
        pop cx              ; Restore counter value for outer loop
        inc si              ; Increment to next bit
    loop loop1              ; End of outer loop
    ret
;
;
;------ Terminate program -------------------------------------------------------
;
terminate:
    call disp_crlf
    int 20h                 ; Terminate program
;
;
;------ Main program ------------------------------------------------------------
;
main:
    call set_scrn           ; Setup screen and cursor position
    call disp_prompt        ; Display prompt
    call get_char           ; Get user character input
    call disp_crlf
    call validate           ; Validate that input is A-E
    call set_pattern        ; Set pattern for output based on input character
    call disp_char          ; Display big version of user input character
    call terminate
;