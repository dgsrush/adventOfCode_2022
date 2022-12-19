#include"raylib.h"
#include"AocUtils.h"

int main(void)
{
	int grid[99][99];
	std::vector<std::string> ll;
	//AocUtils::readInput("sample_input.txt", &ll);
	AocUtils::readInput("input.txt", &ll);

	int colcnt = 0;
	int rowcnt = 0;
	for(std::string ss : ll)
	{
		colcnt = ss.length();
		for(int i = 0; i < colcnt; i++)
		{
			if(ss[i] == 'a') grid[rowcnt][i] = 1;
			else if(ss[i] == 'b') grid[rowcnt][i] = 2;
			else if(ss[i] == 'c') grid[rowcnt][i] = 3;
			else if(ss[i] == 'd') grid[rowcnt][i] = 4;
			else if(ss[i] == 'e') grid[rowcnt][i] = 5;
			else if(ss[i] == 'f') grid[rowcnt][i] = 6;
			else if(ss[i] == 'g') grid[rowcnt][i] = 7;
			else if(ss[i] == 'h') grid[rowcnt][i] = 8;
			else if(ss[i] == 'i') grid[rowcnt][i] = 9;
			else if(ss[i] == 'j') grid[rowcnt][i] = 10;
			else if(ss[i] == 'k') grid[rowcnt][i] = 11;
			else if(ss[i] == 'l') grid[rowcnt][i] = 12;
			else if(ss[i] == 'm') grid[rowcnt][i] = 13;
			else if(ss[i] == 'n') grid[rowcnt][i] = 14;
			else if(ss[i] == 'o') grid[rowcnt][i] = 15;
			else if(ss[i] == 'p') grid[rowcnt][i] = 16;
			else if(ss[i] == 'q') grid[rowcnt][i] = 17;
			else if(ss[i] == 'r') grid[rowcnt][i] = 18;
			else if(ss[i] == 's') grid[rowcnt][i] = 19;
			else if(ss[i] == 't') grid[rowcnt][i] = 20;
			else if(ss[i] == 'u') grid[rowcnt][i] = 21;
			else if(ss[i] == 'v') grid[rowcnt][i] = 22;
			else if(ss[i] == 'w') grid[rowcnt][i] = 23;
			else if(ss[i] == 'x') grid[rowcnt][i] = 24;
			else if(ss[i] == 'y') grid[rowcnt][i] = 25;
			else if(ss[i] == 'z') grid[rowcnt][i] = 26;
			else if(ss[i] == 'S') grid[rowcnt][i] = 1;
			else if(ss[i] == 'E') grid[rowcnt][i] = 26;
		}
		rowcnt++;
	}

	const int screenWidth = 1024;
	const int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Advent Of Code");

	Camera3D camera = { 0 };
	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Vector3 pos = { 0.0f, 0.0f, 0.0f };
	Color c;
	c.g = 0;
	c.b = 0;
	c.a = 255;

	SetCameraMode(camera, CAMERA_FREE);
	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		UpdateCamera(&camera);
		BeginDrawing();
		{
			ClearBackground(DARKBLUE);
			BeginMode3D(camera);
			{
				for(int x = 0; x < rowcnt; x++)
				{
					for(int y = 0; y < colcnt; y++)
					{
						pos.x = x;
						pos.z = y;
						pos.y = grid[x][y];
						c.r = 255 / 26 * pos.y;
						DrawCube(pos, 1.0f, 1.0f, 1.0f, c);
						DrawCubeWires(pos, 1.0f, 1.0f, 1.0f, DARKGRAY);
					}
				}
			}
			EndMode3D();
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
