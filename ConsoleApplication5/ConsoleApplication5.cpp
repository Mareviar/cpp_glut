
#include <iostream>
#include <cstdlib>
#include "glut.h"
#include <dos.h>

float a = 0, b = 0, c = 0, d = 0, e = 0, q = 0, w = 0, f = 0, g = -0.1, h = 0; // координаты рыб
float fb11 = 0, fb12 = 0, fb13 = 0; // координаты пузырьков 1 рыбы
float fb21 = 0, fb22 = 0, fb23 = 0; // координаты пузырьков 2 рыбы
float fb31 = 0, fb32 = 0, fb33 = 0; // координаты пузырьков 3 рыбы
float fb4 = 0;
unsigned char key; int x, y;

void aqua() { // аквариум
	glColor3f(0.0, 0.0, 0.7); // цвет стенок аквариума
	glLineWidth(3.0); // толщина линий
	glBegin(GL_LINE_STRIP); // начало рисования фигуры
	glVertex2f(-1.0, -1.0); // задание вершин линий
	glVertex2f(-0.7, -0.6);
	glVertex2f(0.7, -0.6);
	glVertex2f(1.0, -1.0);
	glVertex2f(1.0, 1.0);
	glVertex2f(0.7, 0.7);
	glVertex2f(-0.7, 0.7);
	glVertex2f(-1.0, 1.0);
	glVertex2f(-1.0, -1.0);
	glEnd(); // окончание
}
void aquaa() { // аквариум конец
	glColor3f(0.0, 0.0, 0.7);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-0.7, 0.7);
	glVertex2f(-0.7, -0.6);
	glVertex2f(0.7, 0.7);
	glVertex2f(0.7, -0.6);
	glEnd();
}

void sand() { // песок
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON); // задание многоугольника
	glVertex2f(-0.9999, -0.9999);
	glVertex2f(-0.7, -0.6);
	glVertex2f(0.7, -0.6);
	glVertex2f(0.9999, -0.9999);
	glEnd();
}

// рыбы 
void fish1() // первая рыба
{
	glColor3f(0.0, 1.0, 0.0);// цвет
	glBegin(GL_POLYGON); // тело рыбы
	glVertex2f(0.25 + a, 0.4 + q);
	glVertex2f(0.26 + a, 0.43 + q);
	glVertex2f(0.3 + a, 0.47 + q);
	glVertex2f(0.34 + a, 0.5 + q);
	glVertex2f(0.5 + a, 0.5 + q);
	glVertex2f(0.52 + a, 0.48 + q);
	glVertex2f(0.56 + a, 0.43 + q);
	glColor3f(0.6, 0.4, 0.0 + q); // изменение цвета вершин
	glVertex2f(0.6 + a, 0.4 + q);
	glVertex2f(0.56 + a, 0.37 + q);
	glColor3f(0.6, 0.4, 0.0 + q);
	glVertex2f(0.52 + a, 0.32 + q);
	glVertex2f(0.5 + a, 0.3 + q);
	glVertex2f(0.34 + a, 0.3 + q);
	glColor3f(0.6, 0.4, 0.0 + q);
	glVertex2f(0.3 + a, 0.33 + q);
	glColor3f(0.0, 1.0, 0.0 + q);
	glVertex2f(0.26 + a, 0.37 + q);
	glEnd();

	glColor3f(1.0, 0.2, 1.0);// 
	glBegin(GL_LINES);
	glVertex2f(0.4 + a, 0.49 + q);
	glVertex2f(0.4 + a, 0.31 + q);
	glVertex2f(0.44 + a, 0.49 + q);
	glVertex2f(0.44 + a, 0.31 + q);
	glVertex2f(0.47 + a, 0.49 + q);
	glVertex2f(0.47 + a, 0.31 + q);
	glVertex2f(0.5 + a, 0.49 + q);
	glVertex2f(0.5 + a, 0.31 + q);
	glEnd();

	glBegin(GL_TRIANGLES); // плавник
	glColor3f(0.5, 0.2, 1.0);
	glVertex2f(0.41 + a, 0.4 + q);
	glVertex2f(0.48 + a, 0.4 + q);
	glVertex2f(0.5 + a, 0.35 + q);
	glEnd();
	glBegin(GL_TRIANGLES); // хвост
	glVertex2f(0.59 + a, 0.4 + q);
	glColor3f(0.6, 0.4, 0.0 + q);
	glVertex2f(0.67 + a, 0.55 + q);
	glVertex2f(0.67 + a, 0.25 + q);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glPointSize(6.0);
	glBegin(GL_POINTS); // задаем границы точки
	glVertex2f(0.32 + a, 0.46 + q);
	glEnd();
}

void fish2() // 2 рыба
{
	glColor3f(0.0, 0.8, 0.8);// 
	glBegin(GL_POLYGON); // тело рыбы
	glVertex2f(0.2 + b, -0.8);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(0.31 + b, -0.75);
	glColor3f(0.0, 0.8, 0.8);
	glVertex2f(0.4 + b, -0.8);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(0.3 + b, -0.9);
	glEnd();

	glColor3f(0.0, 0.8, 0.8);
	glBegin(GL_LINE_STRIP); // хвост
	glVertex2f(0.39 + b, -0.8);
	glVertex2f(0.42 + b, -0.78);
	glVertex2f(0.45 + b, -0.82);
	glVertex2f(0.47 + b, -0.79);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS); // глаз
	glVertex2f(0.27 + b, -0.78);
	glEnd();
}

void fish3() // 3 рыба
{
	glColor3f(0.6, 0.6, 0.6);// цвет
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.4 + c, -0.3 + w);
	glVertex2f(-0.2 + c, -0.25 + w);
	glVertex2f(-0.2 + c, -0.35 + w);
	glEnd();
	glBegin(GL_POLYGON); // тело рыбы

	glVertex2f(-0.2 + c, -0.25 + w);
	glVertex2f(-0.1 + c, -0.15 + w);
	glVertex2f(0.0 + c, -0.1 + w);
	glVertex2f(0.3 + c, -0.1 + w);
	glVertex2f(0.4 + c, -0.12 + w);
	glVertex2f(0.5 + c, -0.2 + w);
	glVertex2f(0.53 + c, -0.25 + w);
	glVertex2f(0.55 + c, -0.3 + w);//верх
	glVertex2f(0.53 + c, -0.35 + w);
	glVertex2f(0.5 + c, -0.4 + w);
	glVertex2f(0.4 + c, -0.48 + w);
	glVertex2f(0.3 + c, -0.5 + w);
	glVertex2f(0.0 + c, -0.5 + w);
	glVertex2f(-0.1 + c, -0.45 + w);
	glVertex2f(-0.2 + c, -0.35 + w);
	glEnd();


	glBegin(GL_POLYGON); // хвост
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(0.537 + c, -0.3 + w);
	glVertex2f(0.7 + c, 0.0 + w);
	glVertex2f(0.64 + c, -0.3 + w);
	glVertex2f(0.7 + c, -0.65 + w);
	glEnd();

	glBegin(GL_TRIANGLES); // плавник
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.05 + c, -0.3 + w);
	glVertex2f(0.37 + c, -0.3 + w);
	glVertex2f(0.5 + c, -0.65 + w);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(6.0);
	glBegin(GL_POINTS); // глаз
	glVertex2f(-0.1 + c, -0.22 + w);
	glEnd();
}

void reversefish() {
	

	glBegin(GL_LINE_STRIP);
	glColor3f(0.2, 0.6, 0.5);
	glVertex2f(0.0+f, 0.0);
	glVertex2f(0.0 + f, 0.25);
	glVertex2f(-0.14 + f, 0.25);
	glVertex2f(-0.14 + f, 0.1);
	glEnd();
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glPointSize(10.0);
	glVertex2f(0.0 + f, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.6, 0.5);
	glVertex2f(-0.06 + f, 0.04);
	glVertex2f(-0.14 + f, 0.1);
	glVertex2f(-0.15 + f, 0.15);
	glVertex2f(-0.25 + f, 0.15);
	glColor3f(0.2, 0.6, 0.0);
	glColor3f(0.3, 0.1, 0.1);
	glVertex2f(-0.3 + f, 0.0);
	glColor3f(0.2, 0.6, 0.5);
	glColor3f(1.0, 0.1, 0.1);
	glVertex2f(-0.25 + f, -0.15);
	glVertex2f(-0.15 + f, -0.15);
	glColor3f(0.2, 0.6, 0.5);
	glVertex2f(-0.06 + f, -0.04);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.06 + f, 0.04);
	glVertex2f(-0.07 + f, 0.0);
	glVertex2f(-0.06 + f, -0.04);
	glEnd();
	glColor3f(0.2, 0.6, 0.5);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3, 0.1, 0.1);
	glVertex2f(-0.29 + f, 0.0);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(-0.37 + f, 0.15);
	glColor3f(0.2, 0.6, 0.0);
	glVertex2f(-0.37 + f, -0.15);
	glEnd();

	glColor3f(0.2, 0.8, 0.4);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.18 + f, 0.01);
	glVertex2f(-0.25 + f, 0.01);
	glColor3f(0.3, 0.1, 0.1);
	glVertex2f(-0.3 + f, -0.13);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glPointSize(3.0);
	glVertex2f(-0.15 + f, 0.1);
	glEnd();
}

void crab() { // краб
	glColor3f(0.5, 0.0, 0.0);
	glLineWidth(3.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.7, -0.65 + d);
	glVertex2f(-0.6, -0.55 + d);
	glVertex2f(-0.45, -0.55 + d);
	glVertex2f(-0.35, -0.65 + d);
	glVertex2f(-0.45, -0.75 + d);
	glVertex2f(-0.6, -0.75 + d);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.78, -0.62 + d);
	glVertex2f(-0.74, -0.62 + d);
	glVertex2f(-0.74, -0.57 + d);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.24, -0.62 + d);
	glVertex2f(-0.28, -0.62 + d);
	glVertex2f(-0.28, -0.57 + d);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.6, -0.55 + d);
	glVertex2f(-0.65, -0.48 + d);
	glVertex2f(-0.45, -0.55 + d);
	glVertex2f(-0.4, -0.48 + d);
	glVertex2f(-0.69, -0.65 + d);
	glVertex2f(-0.74, -0.62 + d);
	glVertex2f(-0.365, -0.65 + d);
	glVertex2f(-0.275, -0.62 + d);
	glVertex2f(-0.64, -0.8 + d);
	glVertex2f(-0.6, -0.75 + d);
	glVertex2f(-0.6, -0.75 + d);
	glVertex2f(-0.56, -0.8 + d);
	glVertex2f(-0.49, -0.8 + d);
	glVertex2f(-0.45, -0.75 + d);
	glVertex2f(-0.45, -0.75 + d);
	glVertex2f(-0.41, -0.8 + d);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);// цвет
	glBegin(GL_LINE_LOOP); // границы, внутри которых задаем
	glVertex2f(-0.65, -0.48 + d);
	glVertex2f(-0.67, -0.49 + d);
	glVertex2f(-0.68, -0.47 + d);
	glVertex2f(-0.68, -0.45 + d);
	glVertex2f(-0.66, -0.45 + d);
	glVertex2f(-0.65, -0.46 + d);// координаты пузырька
	glEnd(); // закрываем

	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);// цвет
	glBegin(GL_LINE_LOOP); // границы, внутри которых задаем
	glVertex2f(-0.415, -0.48 + d);
	glVertex2f(-0.41, -0.49 + d);
	glVertex2f(-0.41, -0.47 + d);
	glVertex2f(-0.38, -0.47 + d);
	glVertex2f(-0.37, -0.48 + d);
	glVertex2f(-0.39, -0.49 + d);
	glEnd(); // закрываем

	glBegin(GL_LINES);
	glVertex2f(-0.55, -0.65 + d);
	glVertex2f(-0.45, -0.65 + d);
	glEnd();
}

void stone() { // камень
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON); // границы, внутри которых задаем
	glVertex2f(0.45, -0.7);
	glVertex2f(0.7, -0.7);
	glVertex2f(0.65, -0.6);
	glVertex2f(0.6, -0.55);
	glVertex2f(0.53, -0.53);
	glVertex2f(0.5, -0.65);
	glEnd();
}

void bubblestone() { // пузырек из под камня
	glLineWidth(2.0);// цвет
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP); // границы, внутри которых задаем
	glVertex2f(0.42, -0.68 + e);
	glVertex2f(0.44, -0.68 + e);
	glVertex2f(0.46, -0.64 + e);
	glVertex2f(0.46, -0.62 + e);
	glVertex2f(0.45, -0.61 + e);
	glVertex2f(0.42, -0.62 + e);// координаты пузырька
	glVertex2f(0.41, -0.64 + e);
	glVertex2f(0.41, -0.68 + e);
	glEnd();
}
// рисование пузырьков рыб
void bubble1() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);// цвет
	glBegin(GL_LINE_LOOP); // границы, внутри которых задаем
	glVertex2f(0.0, 0.4 + fb11);
	glVertex2f(0.02, 0.41 + fb11);
	glVertex2f(0.04, 0.41 + fb11);
	glVertex2f(0.06, 0.4 + fb11);
	glVertex2f(0.04, 0.39 + fb11);
	glVertex2f(0.02, 0.39 + fb11);// координаты пузырька
	glEnd(); // закрываем
}

void bubble2() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);// цвет
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.25, 0.4 + fb12);
	glVertex2f(0.27, 0.41 + fb12);
	glVertex2f(0.29, 0.41 + fb12);
	glVertex2f(0.31, 0.4 + fb12);
	glVertex2f(0.29, 0.39 + fb12);
	glVertex2f(0.27, 0.39 + fb12);

	glEnd(); // закрываем
}

void bubble3() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0);// цвет
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.3, -0.8 + fb21);
	glVertex2f(0.32, -0.78 + fb21);
	glVertex2f(0.34, -0.78 + fb21);
	glVertex2f(0.36, -0.8 + fb21);
	glVertex2f(0.34, -0.82 + fb21);
	glVertex2f(0.32, -0.82 + fb21);

	glEnd(); // закрываем
}

void bubble4() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);// цвет
	glVertex2f(-0.69, -0.8 + fb22); // координаты пузырька
	glVertex2f(-0.71, -0.78 + fb22);
	glVertex2f(-0.73, -0.78 + fb22);
	glVertex2f(-0.75, -0.8 + fb22);
	glVertex2f(-0.73, -0.82 + fb22);
	glVertex2f(-0.71, -0.82 + fb22);
	glEnd(); // закрываем
}

void bubble5() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);// цвет

	glVertex2f(0.1, -0.3 + fb31);
	glVertex2f(0.12, -0.32 + fb31);
	glVertex2f(0.14, -0.32 + fb31);
	glVertex2f(0.16, -0.3 + fb31);
	glVertex2f(0.14, -0.28 + fb31);
	glVertex2f(0.12, -0.28 + fb31);
	glEnd(); // закрываем
}

void bubble6() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);// цвет
	glVertex2f(-0.4, -0.3 + fb32);
	glVertex2f(-0.42, -0.32 + fb32);
	glVertex2f(-0.44, -0.32 + fb32);
	glVertex2f(-0.46, -0.3 + fb32);
	glVertex2f(-0.44, -0.28 + fb32);
	glVertex2f(-0.42, -0.28 + fb32);
	glEnd(); // закрываем
}

void bubble7() {
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);// цвет
	glBegin(GL_LINE_LOOP); // границы, внутри которых задаем
	glVertex2f(-0.04, 0.0 + fb4);
	glVertex2f(-0.02, 0.01 + fb4);
	glVertex2f(0.0, 0.01 + fb4);
	glVertex2f(0.02, 0.0 + fb4);
	glVertex2f(-0.02, -0.01 + fb4);// координаты пузырька
	glEnd(); // закрываем
}

void bubblespeed() { // изменение координат пузырьков
	fb11 += 0.0001;
	fb12 += 0.0001;
	fb13 += 0.0001;
	fb21 += 0.0005;
	fb22 += 0.0006;
	fb31 += 0.0001;
	fb32 += 0.0001;
	fb4 += 0.0001;
	e += 0.00035;
	glutPostRedisplay();
}
// трава
void grass() {
	glColor3f(0.0, 1.0, 0.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2f(-0.2, -0.65);
	glVertex2f(-0.2 + g, -0.25);
	glVertex2f(-0.2, -0.65);
	glVertex2f(-0.1 + g, -0.17);
	glVertex2f(-0.2, -0.65);
	glVertex2f(-0.04 + g, -0.17);
	glVertex2f(-0.2, -0.65);
	glVertex2f(0.05 + g, -0.25);
	glEnd();
}

void grass1() {
	glColor3f(0.0, 1.0, 0.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2f(-0.2, -0.65);
	glVertex2f(-0.15 + g, -0.2);
	glVertex2f(-0.2, -0.65);
	glVertex2f(0.01 + g, -0.2);
	glEnd();
}

// функция отрисовки на экран
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищаем окно 
	aqua();
	aquaa();
	sand();
	grass1();
	fish3();
	grass();
	fish2();
	stone();
	fish1();
	reversefish();
	if (a >= -2)          // когда рыба уплыла за границы экрана
		a = a - 0.0005;         // перемещаем её в другой конец экрана
	else {                    // чтобы она заново поплыла
		a = 0.5;
	}

	if (b >= -1.5)
		b -= 0.0003;          // перемещение рыб
	else {
		b = 0.5;
	}
	if (c >= -3)
		c = c - 0.0003;
	else
		c = 1.1;

	if (f <= 2)
		f += 0.0004;
	else
		f = -1.1;

	if (a <= -0.25)
		bubble1();
	else { fb11 = 0; }
	if (a <= 0.0)
		bubble2();
	else { fb12 = 0; }
	if (b <= 0.1)
		bubble3();
	else { fb21 = 0; }
	if (b <= -0.89)
		bubble4();
	else { fb22 = 0; }
	if (c <= 0.61)
		bubble5();
	else { fb31 = 0; }
	if (c <= -0.1)
		bubble6();
	else { fb32 = 0; }
	if (f >= 0.0)
		bubble7();
	else { fb4 = 0; }

	crab();
	if (b <= -0.56 && b >= -1.2) {
		d += 0.0001;
	}
	else d = 0;
	if (b <= 0.2) {
		bubblestone();
	}
	else e = 0;

	bubblespeed();
	glutPostRedisplay(); // перерисовка
	glFlush(); // инициализация выполнения всех ожидающих программ


}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}
void specialkeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: // если нажимается стрелка вверх
		q += 0.1;  break; // у-координата рыбы увеличивается
	case GLUT_KEY_DOWN: // если нажимается стрелка вниз
		q += -0.1; break; // у-координата рыбы уменьшается
	case GLUT_KEY_LEFT:
		w += 0.1; break; // то же самое с другой рыбой
	case GLUT_KEY_RIGHT:
		w -= 0.1; break;
	}
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);// инициализации GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0); // поцизия окна на экране (в пикселях)
	glutInitWindowSize(780, 780); // размеры окна (в пикселях)
	glutCreateWindow("Рыбки"); // название окна
	glClearColor(0.0, 0.0, 1.1, 0.0); // устанавливает цвет фона 
	glutDisplayFunc(display); // устанавливает функцию рисования для текущего окна
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(specialkeys);
	glutMainLoop(); // процедура обработки событий (по сути бесконечный цикл, в который входит программа)
}