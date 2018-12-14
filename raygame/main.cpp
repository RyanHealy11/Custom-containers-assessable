/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "tVector.h"
#include "tStack.h"
#include "tQueue.h"
#include "tObjectPool.h"
#include"tLinkedList.h"
#include<iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	tVector<int> fuck(4);
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	std::cout << "" << std::endl;
	std::cout << "vector" << std::endl;
	std::cout << fuck.capacity() << std::endl;
	fuck.push_back(5);
	fuck.push_back(6);
	fuck.push_back(6);
	fuck.push_back(7);
	fuck.push_back(8);
	fuck.push_back(9);

	for (int i = 0; i < fuck.size(); i++)
	{
		std::cout << fuck.at(i) << std::endl;

	}
	std::cout << "" << std::endl;
	std::cout << "stack" << std::endl;
	tStack<int> bob;

	bob.push(5);
	std::cout << bob.top() << std::endl;
	bob.push(6);
	std::cout << bob.top() << std::endl;
	bob.pop();
	std::cout << bob.top() << std::endl;
	
	
	
	std::cout << "" << std::endl;
	std::cout << "queue" << std::endl;
	tQueue<int> rob;


	rob.push(5);
	std::cout << rob.front() << std::endl;
	rob.push(6);
	rob.push(7);
	std::cout << rob.back() << std::endl;
	rob.pop();
	std::cout << rob.front() << std::endl;
	rob.pop();
	std::cout << rob.front() << std::endl;

	std::cout << "" << std::endl;
	std::cout << "queue pt2" << std::endl;
	tQueue<int> job(5, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << job.front() << std::endl;
		job.pop();
	}
	if (0) { std::cout << "biuawdnbgkljbasga List" << std::endl; }
	std::cout << "" << std::endl;
	std::cout << "Linked List" << std::endl;

	tForwardList<int> dob;
	dob.push_front(1);
	std::cout << dob.front() << std::endl;
	dob.pop_front();
	dob.push_front(2);
	std::cout << dob.front() << std::endl;
	dob.pop_front();
	dob.push_front(3);
	std::cout << dob.front() << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Linked List pt 2" << std::endl;
	 
	tForwardList<int> fob;
	fob.push_front(1);
	fob.push_front(2);
	fob.push_front(3);
	fob.push_front(4);
	fob.push_front(1);
	fob.push_front(2);
	fob.push_front(3);
	fob.push_front(4);

	fob.remove(37);
	fob.display();

	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	for (auto it = fob.begin(); it != fob.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}