    .intel_syntax noprefix
    .text
    .global sum

sum:
    lea eax, [edi + esi]
    ret
