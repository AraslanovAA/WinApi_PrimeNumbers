.MODEL FLAT, C
.CODE
Task2 PROC D1:dword, D2:dword
	mov eax,dword ptr [ebp+8]	; ���������� ������� ��������
	mov ebx,dword ptr [ebp+12]	; ���������� ������� ��������
	mul eax,ebx
	mov esi, dword ptr [ebp+16]; ���������� �������� ��������
 	mov [esi],eax 			; ���������� ����������
	ret
Task2 ENDP
END