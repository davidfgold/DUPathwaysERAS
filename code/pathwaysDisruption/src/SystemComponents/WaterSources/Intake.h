//
// Created by bernardo on 2/10/17.
//

#ifndef TRIANGLEMODEL_INTAKE_H
#define TRIANGLEMODEL_INTAKE_H


#include "Reservoir.h"

using namespace Constants;

class Intake : public WaterSource {

public:
    double next_upstream_catchment_inflow = 0;

    Intake(
            const char *name, const int id,
            const vector<Catchment *> &catchments,
            const double max_treatment_capacity);

    Intake(
            const char *name, const int id, const vector<Catchment *> &catchments,
            const double raw_water_capacity, const double max_treatment_capacity);

    Intake(const char *name, const int id, const vector<Catchment *> &catchments, vector<int> connected_sources,
           const double raw_water_main_capacity, const vector<double> construction_time_range,
           double permitting_period, Bond &bond);

    Intake(const Intake &intake);

    Intake &operator=(const Intake &intake);

    ~Intake() override;

    void applyContinuity(int week, double upstream_source_min_env_flow,
                             double wastewater_inflow, vector<double> &demand) override;

    void setRealization(unsigned long r, vector<double> &rdm_factors) override;

    double getPrioritySourcePotentialVolume(int utility_id) const override;

};


#endif //TRIANGLEMODEL_INTAKE_H
