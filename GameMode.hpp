#pragma once

#include "Mode.hpp"

#include "MeshBuffer.hpp"
#include "GL.hpp"
#include "Sound.hpp"


#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>

// The 'GameMode' mode is the main gameplay mode:

struct GameMode : public Mode {
	GameMode();
	virtual ~GameMode();

	//handle_event is called when new mouse or keyboard events are received:
	// (note that this might be many times per frame or never)
	//The function should return 'true' if it handled the event.
	virtual bool handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) override;

	//update is called at the start of a new frame, after events are handled:
	virtual void update(float elapsed) override;

	//draw is called after update:
	virtual void draw(glm::uvec2 const &drawable_size) override;

	float camera_spin = 0.0f;
	float spot_spin = 0.0f;
	float plate_dir = 0.0f;
	float plate_spin = 0.0f;

	float count = 0.0f;
	int dir = 1;
	float limit = 1.0f;
	float life = 10.0f;
	float score = 0.0f;
	bool lose = false;

	std::shared_ptr< Sound::PlayingSample > loop;
};
