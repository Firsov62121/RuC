float pow (int x, int y)	// pow (x, y ) -- x^ y, делаю функцию возведения в степень
{
int i = 0, j = 0;
float tmp = 1;
if  (y > 0)
{
	while (i < y)
	{
		tmp = tmp *x;
		i++;
	}
}
if (y < 0 )
{
	while (j > y)
	{
		tmp = tmp*x;
		j--;
		if (j == y)
			tmp = 1.0/tmp;	
	}
}
if (y == 1)
tmp = x;
if ( y ==0 &&  x != 0)
tmp = 1;
return tmp;
}

void main ()
{
int i, j,error,k,l,p,N;	// i, j - индексы для циклов,  error - индекс ошибок (если error >0 - ошибка, если error = 0 - всё хорошо)
float numb;                     // k - показывает на каком месте стоит точка, если она есть
char sign, B[11];		// l - показывает по какому пути считать число numb, p - помогает в отлове ошибок, если ввели более одной точки
numb = 0;		// N - кол-во литер, sign - литера, B[11] - "стандартный" массив, там есть цифры и точка
error = 0;
l = p = 0;
print ( "Введите количество: " );
getid (N);
{
char A[N]; int  C[N];	// массив A - массив литер (на самом деле - массив их кодировок (сдвинутый)), массив C помогает в поиске ошибок
if (N > 10)
	print ( "Слишком много!" );
else
{
for (i = 0; i < N; i++)	// обнуляем массив A
{
	A[i] = 0;		
}
for (j = 0; j < 10; j++)	// заполняем массив B
{
	B[j] = j;
}
B[10] = '.';
print ( "Введите литеры: ");
for (i = 0; i < N;i++)	// ввод литер, заполнение массива A их сдвинутыми кодировками (так удобнее)
{
	getid (sign);
	A[i] = sign - 48;
	for (j = 0; j < 10;j++)	// заполняем массив C для ловли ошибок, массивы B, С я не обнулял перед заполнением, но вроде бы и так нормально
	{
		if ( A[i] != B[j])
		C[i]++;
	}
	if (A[i]  != -2)
		C[i] = C[i] +2;	
}
for (i = 0; i < N; i++)	// нахождение ошибки ввода не тех литер (например, 'a', 'b' и т.д.)
{
	if (C[i] == 12)
			error++;	
}
for (i = 0; i < N; i++)	// это делается, чтобы нельзя было вводить более одной точки
{
	if ( C[i] % 10 == 0 )
		p++;
}
if (p > 1)
	error++;
for (i = 0; i < N; i++)	// ищется позиция точки (-2 - сдвинутый код точки)
{
	if (A[i] == -2)
	{
		l++;
		k = i;
	}
}
if (l > 0)		// счёт числа, l = 0 -число целое, l = 1 - вещественное (рациональное) 
{
	for (j = 0; j < k; j++)
	{
		numb +=  A[j] * pow (10, k - j -1 );
	}
	for (j = k + 1; j < N; j++)
	{
		numb = numb + A[j] * pow (10, k - j);
	}
}
else
{
	for (i = 0; i < N; i++)
	{
		numb +=  A[i] * pow (10, N - i -1);
	}
}
if (error > 0)	// вывод сообщения об ошибке, если error > 0, если error = 0, то вывод numb
print ( "Ошибка" );
else
printid (numb);
}
}
}