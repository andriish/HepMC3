// -*- C++ -*-
//
// This file is part of HepMC
// Copyright (C) 2014-2026 The HepMC collaboration (see AUTHORS for details)
//
#ifndef HEPMC3_HDF5UTILS_H
#define HEPMC3_HDF5UTILS_H

#include <cstdint>
#include <string>
#include <vector>
#include "HepMC3/highfive/H5File.hpp"

#include "HepMC3/FourVector.h"
#include "HepMC3/Data/GenEventData.h"
#include "HepMC3/Data/GenParticleData.h"
#include "HepMC3/Data/GenVertexData.h"
#include "HepMC3/Data/GenRunInfoData.h"

namespace HepMC3 {

/// @brief HDF5 utility helper functions.
namespace Hdf5Utils {

/// @brief HDF5 representation of a four-vector.
struct H5FourVector {
    /// @brief x component.
    double x;
    /// @brief y component.
    double y;
    /// @brief z component.
    double z;
    /// @brief Time or energy component.
    double t;
};

/// @brief HDF5 representation of a particle record.
struct H5Particle {
    /// @brief PDG identifier.
    int pid;
    /// @brief HepMC status code.
    int status;
    /// @brief Whether the mass field is explicitly set.
    uint8_t is_mass_set;
    /// @brief Generated mass.
    double mass;
    /// @brief Four-momentum.
    H5FourVector momentum;
};

/// @brief HDF5 representation of a vertex record.
struct H5Vertex {
    /// @brief HepMC status code.
    int status;
    /// @brief Space-time position.
    H5FourVector position;
};

/// @brief Variable-length run information stored in HDF5 datasets.
struct H5RunInfo {
    /// @brief Event weight names.
    std::vector<std::string> weight_names;
    /// @brief Generator tool names.
    std::vector<std::string> tool_name;
    /// @brief Generator tool versions.
    std::vector<std::string> tool_version;
    /// @brief Generator tool descriptions.
    std::vector<std::string> tool_description;
    /// @brief Run attribute names.
    std::vector<std::string> attribute_name;
    /// @brief Serialized run attribute values.
    std::vector<std::string> attribute_string;
};

/// @brief Offsets and counts for variable-length run information.
struct H5RunInfoIndex {
    /// @brief Offset of weight names.
    uint64_t weight_names_offset;
    /// @brief Number of weight names.
    uint64_t weight_names_count;
    /// @brief Offset of tool information.
    uint64_t tool_offset;
    /// @brief Number of tools.
    uint64_t tool_count;
    /// @brief Offset of attributes.
    uint64_t attribute_offset;
    /// @brief Number of attributes.
    uint64_t attribute_count;
};

/// @brief Fixed-size event index record stored in the events dataset.
struct H5EventIndex {
    /// @brief Event number.
    int event_number;
    /// @brief Encoded momentum unit.
    int momentum_unit;
    /// @brief Encoded length unit.
    int length_unit;
    /// @brief Event position.
    H5FourVector event_pos;

    /// @brief Offset of event particles.
    uint64_t particles_offset;
    /// @brief Number of event particles.
    uint64_t particles_count;
    /// @brief Offset of event vertices.
    uint64_t vertices_offset;
    /// @brief Number of event vertices.
    uint64_t vertices_count;

    /// @brief Offset of event weights.
    uint64_t weights_offset;
    /// @brief Number of event weights.
    uint64_t weights_count;
    /// @brief Offset of vertex-particle links.
    uint64_t links_offset;
    /// @brief Number of vertex-particle links.
    uint64_t links_count;

    /// @brief Offset of event attributes.
    uint64_t attribute_offset;
    /// @brief Number of event attributes.
    uint64_t attribute_count;
    /// @brief Index of the associated run information.
    uint64_t run_info_index;
};

/// @brief In-memory event data assembled from HDF5 datasets.
struct H5EventRecord {
    /// @brief Event number.
    int event_number;
    /// @brief Encoded momentum unit.
    int momentum_unit;
    /// @brief Encoded length unit.
    int length_unit;
    /// @brief Event position.
    H5FourVector event_pos;

    /// @brief Event particles.
    std::vector<H5Particle> particles;
    /// @brief Event vertices.
    std::vector<H5Vertex> vertices;

    /// @brief Event weights.
    std::vector<double> weights;
    /// @brief First vertex-particle link indices.
    std::vector<int> links1;
    /// @brief Second vertex-particle link indices.
    std::vector<int> links2;

    /// @brief Attribute identifiers.
    std::vector<int> attribute_id;
    /// @brief Attribute names.
    std::vector<std::string> attribute_name;
    /// @brief Serialized attribute values.
    std::vector<std::string> attribute_string;

    /// @brief Associated run information.
    H5RunInfo run_info;
};

/// @brief Create the HDF5 compound type for H5FourVector.
inline HighFive::CompoundType createFourVectorType() {
    return HighFive::CompoundType{
        {"x", HighFive::AtomicType<double>{}},
        {"y", HighFive::AtomicType<double>{}},
        {"z", HighFive::AtomicType<double>{}},
        {"t", HighFive::AtomicType<double>{}}
    };
}

/// @brief Create the HDF5 compound type for H5Particle.
inline HighFive::CompoundType createParticleType() {
    return HighFive::CompoundType{
        {"pid",         HighFive::AtomicType<int>{}},
        {"status",      HighFive::AtomicType<int>{}},
        {"is_mass_set", HighFive::AtomicType<uint8_t>{}},
        {"mass",        HighFive::AtomicType<double>{}},
        {"momentum",    createFourVectorType()}
    };
}

/// @brief Create the HDF5 compound type for H5Vertex.
inline HighFive::CompoundType createVertexType() {
    return HighFive::CompoundType{
        {"status",   HighFive::AtomicType<int>{}},
        {"position", createFourVectorType()}
    };
}

/// @brief Create the HDF5 compound type for H5EventIndex.
inline HighFive::CompoundType createEventIndexType() {
    return HighFive::CompoundType{
        {"event_number",           HighFive::AtomicType<int>{}},
        {"momentum_unit",          HighFive::AtomicType<int>{}},
        {"length_unit",            HighFive::AtomicType<int>{}},
        {"event_pos",              createFourVectorType()},
        {"particles_offset",       HighFive::AtomicType<uint64_t>{}},
        {"particles_count",        HighFive::AtomicType<uint64_t>{}},
        {"vertices_offset",        HighFive::AtomicType<uint64_t>{}},
        {"vertices_count",         HighFive::AtomicType<uint64_t>{}},
        {"weights_offset",         HighFive::AtomicType<uint64_t>{}},
        {"weights_count",          HighFive::AtomicType<uint64_t>{}},
        {"links_offset",           HighFive::AtomicType<uint64_t>{}},
        {"links_count",            HighFive::AtomicType<uint64_t>{}},
        {"attribute_offset",       HighFive::AtomicType<uint64_t>{}},
        {"attribute_count",        HighFive::AtomicType<uint64_t>{}}
    };
}

/// @brief Create the HDF5 compound type for H5RunInfoIndex.
inline HighFive::CompoundType createRunInfoIndexType() {
    return HighFive::CompoundType{
        {"weight_names_offset",      HighFive::AtomicType<uint64_t>{}},
        {"weight_names_count",       HighFive::AtomicType<uint64_t>{}},
        {"tool_offset",              HighFive::AtomicType<uint64_t>{}},
        {"tool_count",               HighFive::AtomicType<uint64_t>{}},
        {"attribute_offset",         HighFive::AtomicType<uint64_t>{}},
        {"attribute_count",          HighFive::AtomicType<uint64_t>{}}
    };
}

/// @brief Convert a HepMC four-vector to its HDF5 representation.
inline H5FourVector toH5(const FourVector& v) {
    return H5FourVector{v.x(), v.y(), v.z(), v.t()};
}

/// @brief Convert an HDF5 four-vector to its HepMC representation.
inline FourVector fromH5(const H5FourVector& v) {
    return FourVector{v.x, v.y, v.z, v.t};
}

/// @brief Convert serialized particle data to its HDF5 representation.
inline H5Particle toH5(const GenParticleData& p) {
    return H5Particle{
        p.pid,
        p.status,
        static_cast<uint8_t>(p.is_mass_set ? 1 : 0),
        p.mass,
        toH5(p.momentum)
    };
}

/// @brief Convert an HDF5 particle record to serialized particle data.
inline GenParticleData fromH5(const H5Particle& p) {
    return GenParticleData{
        p.pid,
        p.status,
        p.is_mass_set != 0,
        p.mass,
        fromH5(p.momentum)
    };
}

/// @brief Convert serialized vertex data to its HDF5 representation.
inline H5Vertex toH5(const GenVertexData& v) {
    return H5Vertex{
        v.status,
        toH5(v.position)
    };
}

/// @brief Convert an HDF5 vertex record to serialized vertex data.
inline GenVertexData fromH5(const H5Vertex& v) {
    return GenVertexData{
        v.status,
        fromH5(v.position)
    };
}

/// @brief Convert serialized run information to its HDF5 representation.
inline H5RunInfo toH5(const GenRunInfoData& rd) {
    return H5RunInfo{
        rd.weight_names,
        rd.tool_name,
        rd.tool_version,
        rd.tool_description,
        rd.attribute_name,
        rd.attribute_string
    };
}

/// @brief Convert HDF5 run information to serialized run information.
inline GenRunInfoData fromH5(const H5RunInfo& rd) {
    return GenRunInfoData{
        rd.weight_names,
        rd.tool_name,
        rd.tool_version,
        rd.tool_description,
        rd.attribute_name,
        rd.attribute_string
    };
}

/// @brief Convert serialized event data to HDF5 records.
inline H5EventRecord toH5(const GenEventData& ev) {
    H5EventRecord record;
    record.event_number = ev.event_number;
    record.momentum_unit = static_cast<int>(ev.momentum_unit);
    record.length_unit = static_cast<int>(ev.length_unit);
    record.event_pos = toH5(ev.event_pos);

    record.particles.reserve(ev.particles.size());
    for (const auto& p : ev.particles) {
        record.particles.push_back(toH5(p));
    }

    record.vertices.reserve(ev.vertices.size());
    for (const auto& v : ev.vertices) {
        record.vertices.push_back(toH5(v));
    }

    record.weights = ev.weights;
    record.links1 = ev.links1;
    record.links2 = ev.links2;
    record.attribute_id = ev.attribute_id;
    record.attribute_name = ev.attribute_name;
    record.attribute_string = ev.attribute_string;


    return record;
}

/// @brief Convert HDF5 event records to serialized event data.
inline GenEventData fromH5(const H5EventRecord& record) {
    GenEventData ev;
    ev.event_number = record.event_number;
    ev.momentum_unit = static_cast<Units::MomentumUnit>(record.momentum_unit);
    ev.length_unit = static_cast<Units::LengthUnit>(record.length_unit);
    ev.event_pos = fromH5(record.event_pos);

    ev.particles.reserve(record.particles.size());
    for (const auto& p : record.particles) {
        ev.particles.push_back(fromH5(p));
    }

    ev.vertices.reserve(record.vertices.size());
    for (const auto& v : record.vertices) {
        ev.vertices.push_back(fromH5(v));
    }

    ev.weights = record.weights;
    ev.links1 = record.links1;
    ev.links2 = record.links2;
    ev.attribute_id = record.attribute_id;
    ev.attribute_name = record.attribute_name;
    ev.attribute_string = record.attribute_string;

    return ev;
}
template <typename T>
/// @brief Read a contiguous range from an HDF5 dataset.
inline void readVector(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<T> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read(out);
}

template <>
/// @brief Read H5EventIndex records from an HDF5 dataset.
inline void readVector<H5EventIndex>(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<H5EventIndex> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read_raw(out.data(), createEventIndexType());
}

template <>
/// @brief Read H5Particle records from an HDF5 dataset.
inline void readVector<H5Particle>(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<H5Particle> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read_raw(out.data(), createParticleType());
}

template <>
/// @brief Read H5Vertex records from an HDF5 dataset.
inline void readVector<H5Vertex>(const HighFive::DataSet &ds, uint64_t offset, uint64_t count, std::vector<H5Vertex> &out) {
    out.clear();
    if (count == 0) {
        return;
    }
    out.resize(count);
    ds.select(std::vector<size_t>{static_cast<size_t>(offset)}, std::vector<size_t>{static_cast<size_t>(count)}).read_raw(out.data(), createVertexType());
}

template <typename T>
/// @brief Append values to a one-dimensional HDF5 dataset.
inline void appendVector(HighFive::DataSet &dataset, const std::vector<T> &data) {
    std::vector<size_t> current_dims = dataset.getDimensions();
    std::size_t offset = current_dims.empty() ? 0 : current_dims[0];
    std::vector<size_t> new_dims{offset + data.size()};
    dataset.resize(new_dims);
    if (!data.empty()) {
        dataset.select(std::vector<size_t>{offset}, std::vector<size_t>{data.size()}).write(data);
    }
}

template <typename T>
/// @brief Append values using an explicit HDF5 data type.
inline void appendVector(HighFive::DataSet &dataset, const std::vector<T> &data, const HighFive::DataType &dtype) {
    std::vector<size_t> current_dims = dataset.getDimensions();
    std::size_t offset = current_dims.empty() ? 0 : current_dims[0];
    std::vector<size_t> new_dims{offset + data.size()};
    dataset.resize(new_dims);
    if (data.empty()) {
        return;
    }
    dataset.select(std::vector<size_t>{offset}, std::vector<size_t>{data.size()}).write_raw(data.data(), dtype);
}

/// @brief Append raw values using an explicit HDF5 data type.
inline void appendRaw(HighFive::DataSet &dataset, const void *data, uint64_t count, const HighFive::DataType &dtype) {
    std::vector<size_t> current_dims = dataset.getDimensions();
    uint64_t offset = current_dims.empty() ? 0 : current_dims[0];
    std::vector<size_t> new_dims{offset + count};
    dataset.resize(new_dims);
    if (count == 0) {
        return;
    }
    dataset.select(std::vector<size_t>{offset}, std::vector<size_t>{static_cast<size_t>(count)}).write_raw(data, dtype);
}


} // namespace Hdf5Utils

} // namespace HepMC3

#endif // HEPMC3_HDF5UTILS_H
