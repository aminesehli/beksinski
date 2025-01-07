#include "brushes.h"
#include <GLFW/glfw3.h>
#include <cmath>

void brushes::drawCircle(double x, double y, float radius, int segments)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);
		float dx = radius * cosf(theta);
		float dy = radius * sinf(theta);
		glVertex2f(x + dx, y + dy);
	}
	(glEnd());
}