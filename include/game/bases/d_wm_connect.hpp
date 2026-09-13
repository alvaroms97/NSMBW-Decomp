#pragma once
#include <types.h>
#include <game/mLib/m_vec.hpp>
#include <game/bases/d_wm_csvdata.hpp>
#include <game/mLib/m_3d/mdl.hpp>

/// @brief Builds and stores the connectivity graph between the points of a world map.
/// @ingroup bases
class dWmConnect_c {
public:
    /// @brief A single point of the world map connectivity graph.
    /// @unofficial
    class dPnt_c {
    public:
        /// @brief Sets this point's name, world-space position, and index.
        /// @param pointName The name of the point.
        /// @param pointPos The world-space position of the point.
        /// @param index The index of the point.
        void SetInfo(const char *pointName, nw4r::math::VEC3 &pointPos, int index);

        void init(); ///< Resets this point to its default (unnamed, unlinked) state.

        /// @brief Returns the point linked in the given direction.
        /// @param dir The link direction, per dWmLib::Direction3D_e.
        /// @return The linked point, or @p nullptr if there is no link in that direction.
        dPnt_c *GetLink(int dir);

        u32 m_00; ///< @unofficial Unknown. Never read/written by any decompiled code so far.
        char name[8]; ///< @unofficial Only the first MAX_POINT_NAME_LEN bytes are used.
        nw4r::math::VEC3 pos; ///< The world-space position of the point.
        dPnt_c *mLink[6]; ///< The points linked to this one, per dWmLib::Direction3D_e, or @p nullptr.
        s32 mActionLabel[6]; ///< @unofficial dCsvData_c::ActionType_e per link direction.
        s32 mCourseNo; ///< The course number of the point, or @p -1 if it is not a course entrance.
        s32 mPointIndex; ///< The index of the point.
        s32 mIsValid; ///< @unofficial Whether the point is usable for pathing (not a special/hidden node).
    };

    /// @brief Sets each point's world-space position from @p model and whether it is usable for pathing.
    /// @param csvData The point/route data to read point names and flags from.
    /// @param model The world map model to read point positions from.
    void SetInfo(dCsvData_c &csvData, const m3d::mdl_c &model);

    /// @brief Initializes every point, its course number, its connections and its route animations.
    /// @param csvData The point/route data to initialize from.
    /// @param model The world map model to read point positions from.
    void initialize(dCsvData_c &csvData, const m3d::mdl_c &model);

    /// @brief Connects the start and end points of every subroute in @p csvData to each other.
    /// @param csvData The point/route data to read subroutes from.
    void calcConnect(dCsvData_c &csvData);

    /// @brief Returns the index of the point with the given name.
    /// @param name The name of the point to search for.
    /// @return The point's index, or @p -1 if not found.
    int GetPointNo(const char *name);

    /// @brief Links points @p a and @p b to each other, in the link direction determined by their
    /// relative world-space position.
    /// @param a The index of the first point.
    /// @param b The index of the second point.
    /// @return Always @p true.
    /// @unofficial
    bool __connect(int a, int b);

    /// @brief Determines the route animation action label for each point's existing connections.
    /// @param csvData The point/route data to read route action labels from.
    void initAnimation(dCsvData_c &csvData);

    /// @brief Sets the course number for the point at the given index, from its name.
    /// @param index The index of the point.
    void SetCourseNo(int index);

    /// @brief Returns the course number of the point with the given name.
    /// @param name The name of the point to search for.
    /// @return The point's course number, or @p -1 if not found.
    int GetCourseNoFromName(const char *name);

    /// @brief Returns the point linked to the point with the given name, in the given direction.
    /// @param name The name of the point to search for.
    /// @param dir The link direction, per dWmLib::Direction3D_e.
    /// @return The linked point, or @p nullptr if not found or not linked in that direction.
    dPnt_c *GetConnect(const char *name, int dir);

    /// @brief Returns the point with the given point index.
    /// @param index The point index to search for.
    /// @return The matching point, or @p nullptr if not found.
    dPnt_c *GetPointFromIndex(int index);

    /// @brief Returns the link direction connecting the points at the given indices.
    /// @param indexA The index of the first point.
    /// @param indexB The index of the second point.
    /// @return The link direction, per dWmLib::Direction3D_e, or @p 6 if they are not directly linked.
    int GetDir(int indexA, int indexB);

    u32 m_00; ///< @unofficial Unknown. Never read/written by any decompiled code so far.
    dPnt_c mPoints[MAX_POINT_COUNT]; ///< The points of the world map.
    s32 mWorld; ///< @unofficial Copied from dCsvData_c::mWorld during initialize().
};
