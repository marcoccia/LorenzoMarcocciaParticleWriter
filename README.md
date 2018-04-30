
*******************************************************************************

			                       README
				                      
*******************************************************************************

I. Several useful file list
------------

setup.sh                    setup ATLAS environment (needed only if you use Rome2 farm)
particle_list.txt           contains data to analysize
FirstParticleExercise.cxx   reads data and makes ntuples
treeAnalysis.C			    reads ntuples and makes distributions and fits
executeAll.sh               executes all the .C files

II. How to Run
--------------

- command < source executeAll.sh >
- This command executes all the code and produces images electronsFit.png, muonsFit.png and pionsFit.png and the file fit.root in the subfolder macros/.
- In electronsFit.png, muonsFit.png and pionsFit.png you can see the energy distributions (for e+/e-, mu+/mu- and pi+/pi-). 
- Fit results (values of Mean, sigma and goodness of the fit) are printed on screen.
 

III. Diagram
------------
			            |---------------------|
			            |  particle_list.txt  |
			            |---------------------|
			                        |
			                        |                          
			                        |
			         |------------------------------|
			         |   FirstParticleExercise.cxx  |
			         |------------------------------|
			                        |
			                        |                          
			                        |
			           |------------------|
			               |  treeAnalysis.C  |
			               |------------------|
			                        |
			                        |                          
			                        |
			|--------------------------------------------------|
			| electronsFit.png, muonsFit.png and pionsFit.png  |
			|--------------------------------------------------|
	                        
IV. Enjoy!
------------
