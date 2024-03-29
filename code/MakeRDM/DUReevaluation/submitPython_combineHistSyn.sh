
RDM_PER_JOB=20
N_NODES=10
TASKS_PER_NODE=10
START_RDM=1

TOTAL_TASKS=$(($N_NODES*$TASKS_PER_NODE))

SLURM="#!/bin/bash\n\
#SBATCH -n $TOTAL_TASKS -N $N_NODES\n\
#SBATCH --time=5:00:00\n\
#SBATCH --job-name=python_combine_${START_RDM}_to_$(($START_RDM+$TOTAL_TASKS))\n\
#SBATCH --output=output/python_combine_${START_RDM}_to_$(($START_RDM+$TOTAL_TASKS)).out\n\
#SBATCH --error=output/python_combine_${START_RDM}_to_$(($START_RDM+$TOTAL_TASKS)).err\n\
#SBATCH --exclusive\n\
module load py3-mpi4py\n\
module load py3-numpy\n\
module load R\n\
time mpirun -np $TOTAL_TASKS python3 pythonCombineHistoricalSyntheticInflows.py $START_RDM $TOTAL_TASKS $RDM_PER_JOB"

echo -e $SLURM | sbatch
sleep 0.5
#donemod
