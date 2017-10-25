# SlenderMan

A slenderman game like Slender: The Eight Pages.

I started creating this on 17th October 2017, and my goal as to complete it in 2 weeks (In time for Halloween)

Made using C++/ OpenGL.

### Building:
<coming soon>

# The challenge

I started off using the simple SFML game framework, and created it from there.

This means the line total shown below is 857 lesser than the true value (Line of code of the framework I made.)

### Day 1 & 2

Day one was spent setting up basic OpenGL stuff, such as support for actually drawing in OpenGL, 3D, an FPS camera, and a simple render system

![Day 1](https://i.imgur.com/KsXOV40.png)

End of day 2 stats:

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 3:15:48                                                    	|
| Lines of Code Today    	| 575                                                           |
| Total Time Programming 	| 3:15:48                                                    	|
| Total Lines of Code    	| 575                                                           |

### Day 3

Today I did not get much done due to some kind of flu.

However, what I did do was get model loading in the game. This uses a parser my friend wrote a while back while following the ThinMatrix OpenGL tutorial.

Before this, I tried using TinyOBJ and Assimp, but neither of those worked.

![Day 3](https://i.imgur.com/vOuaSIT.png)

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 2:52:41                                            	|
| Lines of Code Today    	| 369                                                           |
| Total Time Programming 	| 6:08:29                                                    	|
| Total Lines of Code    	| 944                                                           |

### Day 4

Today was started off by getting terrain to be generated and render, and finished off with some
lighting effects

![Day 4](https://i.imgur.com/fORH4A9.png)

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 2:13:10                                                       |
| Lines of Code Today    	| 242                                                           |
| Total Time Programming 	| 8:21:39                                                    	|
| Total Lines of Code    	| 1186                                                           |


### Day 5

To begin, I created a level loader. This simply take in a .png image, and then places objects at
location, using hexadecimal colours.

After this, I begun work on a post processing shader, which crashes, so I was unable to use it.

Failing with that, I also improved how the torch looks, by moving the position of it slightly Down
and to the right of the camera. This makes it look better as it actually looks like you are
holding a torch, as opposed to just having light come out your mouth or something.

To finish off, I created a player class, which allows for smoother movement though the use of velocity.

![Day 5](https://i.imgur.com/FjCcsEQ.jpg)

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 3:40:49                                                      |
| Lines of Code Today    	| 245                                                           |
| Total Time Programming 	| 12:02:28                                                    	|
| Total Lines of Code    	| 1432                                                           |


### Day 6

Not much was done today because I was busy with other stuff.

However, I made a skybox for some additional ambience, and added an "edge" to the level.

![Day 6](https://i.imgur.com/d4YW8cW.png)

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 1:55:12                                                      |
| Lines of Code Today    	| 280                                                           |
| Total Time Programming 	| 13:57:40                                                    	|
| Total Lines of Code    	| 1712                                                           |


### Day 7

Not much was done today because I was busy with other stuff.

One thing I did do was add in slender boi

He does not do much, as for now he is literally a texture that renders to a quad, of which always
faces the player.

Other things I did was some clean up.

![Day 7](https://i.imgur.com/w6Uq1rD.jpg)

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 0:42:12                                                      |
| Lines of Code Today    	| 193                                                   |
| Total Time Programming 	| 14:39:52                                                    	|
| Total Lines of Code    	| 1905                                                           |


### Day 8

I added the initial logic of Slenderman himself today.

This is testing whether he is in view, or not.

First of all, I test if he inside of the viewing frustum of the player. If he is, the next text is the occlusion test, which is testing if main man is behind an entity, or actually in view.

| Title                  	| Data                                                       	|
|------------------------	|------------------------------------------------------------	|
| Time programming Today 	| 0:59:54                                                      |
| Lines of Code Today    	| 126                                                   |
| Total Time Programming 	| 15:39:46                                                    	|
| Total Lines of Code    	| 1905                                                           |









                                                         |

