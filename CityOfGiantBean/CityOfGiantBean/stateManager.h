#pragma once
#include "Tools.h"

class stateManager;

class State
{
protected:
    stateManager* stateManager_;
public:
    virtual ~State()
    {

    }

    void set_stateManager(stateManager* _stateManager)
    {
        this->stateManager_ = _stateManager;
    }

    virtual void init(myWindow& _window) = 0;
    virtual void update(myWindow& _window) = 0;
    virtual void updateEvent(myWindow& _window) = 0;
    virtual void draw(myWindow& _window) = 0;
    virtual void destroy() = 0;
};

class stateManager {

private:
    State* state_;

public:
    stateManager(State* state, myWindow& _window) : state_(nullptr) {
        this->TransitionTo(state, _window);
    }
    ~stateManager() {
        delete state_;
    }

    void TransitionTo(State* state, myWindow& _window) {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_stateManager(this);
        this->RequestInit(_window);
    }

    void RequestInit(myWindow& _window)
    {
        this->state_->init(_window);
    }
    void RequestUpdate(myWindow& _window)
    {
        this->state_->update(_window);
    }
    void RequestUpdateEvent(myWindow& _window)
    {
        while (_window.getRenderWindow().pollEvent(_window.GetEvent()))
        {
            if (_window.GetEvent().type == sf::Event::Closed)
            {
                _window.SetIsDone(true);
            }
            else if (_window.GetEvent().type == sf::Event::KeyPressed && _window.GetEvent().key.code == sf::Keyboard::F5)
            {
                _window.ToggleFullscreen();
            }
            this->state_->updateEvent(_window);
        }
    }
    void RequestDraw(myWindow& _window)
    {
        this->state_->draw(_window);
    }
    void RequestDestroy()
    {
        this->state_->destroy();
    }
};