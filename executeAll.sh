echo " Do you use Rome 2 Farm or lxplus? (y/n) "
read answ
if [[ ${answ} == "y" || ${answ} == "Y" ]]; then
source setup.sh
fi

if [ -d "$ROOTSYS" ]; then
echo "ROOT control... "
echo "done "
else 
echo " Error: I can't find ROOT "
exit 0
fi

make
./bin/FirstParticleExercise
./bin/treeAnalysis
