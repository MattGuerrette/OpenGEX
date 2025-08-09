//
// This file is part of the Terathon OpenGEX Import Template, by Eric Lengyel.
// Copyright 2013-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//

#ifndef OpenGEX_h
#define OpenGEX_h

#include "TSColor.h"
#include "TSOpenDDL.h"
#include "TSQuaternion.h"

#include <list>
#include <string>
#include <unordered_map>

using namespace Terathon;

namespace OpenGEX
{
    enum : StructureType
    {
        kStructureMetric = 'mtrc',
        kStructureName = 'name',
        kStructureObjectRef = 'obrf',
        kStructureMaterialRef = 'mtrf',
        kStructureMatrix = 'mtrx',
        kStructureTransform = 'xfrm',
        kStructureTranslation = 'xslt',
        kStructureRotation = 'rota',
        kStructureScale = 'scal',
        kStructureMorphWeight = 'mwgt',
        kStructureNode = 'node',
        kStructureBoneNode = 'bnnd',
        kStructureGeometryNode = 'gmnd',
        kStructureLightNode = 'ltnd',
        kStructureCameraNode = 'cmnd',
        kStructureVertexArray = 'vert',
        kStructureIndexArray = 'indx',
        kStructureBoneRefArray = 'bref',
        kStructureBoneCountArray = 'bcnt',
        kStructureBoneIndexArray = 'bidx',
        kStructureBoneWeightArray = 'bwgt',
        kStructureSkeleton = 'skel',
        kStructureSkin = 'skin',
        kStructureMorph = 'mrph',
        kStructureMesh = 'mesh',
        kStructureObject = 'objc',
        kStructureGeometryObject = 'gmob',
        kStructureLightObject = 'ltob',
        kStructureCameraObject = 'cmob',
        kStructureAttrib = 'attr',
        kStructureParam = 'parm',
        kStructureColor = 'colr',
        kStructureSpectrum = 'spec',
        kStructureTexture = 'txtr',
        kStructureAtten = 'attn',
        kStructureMaterial = 'matl',
        kStructureKey = 'key ',
        kStructureCurve = 'curv',
        kStructureTime = 'time',
        kStructureValue = 'valu',
        kStructureTrack = 'trac',
        kStructureAnimation = 'anim',
        kStructureClip = 'clip'
    };

    enum : DataResult
    {
        kDataOpenGexInvalidUpDirection = 'ivud',
        kDataOpenGexInvalidForwardDirection = 'ivfd',
        kDataOpenGexInvalidTranslationKind = 'ivtk',
        kDataOpenGexInvalidRotationKind = 'ivrk',
        kDataOpenGexInvalidScaleKind = 'ivsk',
        kDataOpenGexDuplicateLod = 'dlod',
        kDataOpenGexMissingLodSkin = 'mlsk',
        kDataOpenGexMissingLodMorph = 'mlmp',
        kDataOpenGexDuplicateMorph = 'dmph',
        kDataOpenGexUndefinedLightType = 'ivlt',
        kDataOpenGexUndefinedCurve = 'udcv',
        kDataOpenGexUndefinedAtten = 'udan',
        kDataOpenGexDuplicateVertexArray = 'dpva',
        kDataOpenGexPositionArrayRequired = 'parq',
        kDataOpenGexVertexCountUnsupported = 'vcus',
        kDataOpenGexIndexValueUnsupported = 'ivus',
        kDataOpenGexIndexArrayRequired = 'iarq',
        kDataOpenGexVertexCountMismatch = 'vcmm',
        kDataOpenGexBoneCountMismatch = 'bcmm',
        kDataOpenGexBoneWeightCountMismatch = 'bwcm',
        kDataOpenGexInvalidBoneRef = 'ivbr',
        kDataOpenGexInvalidObjectRef = 'ivor',
        kDataOpenGexInvalidMaterialRef = 'ivmr',
        kDataOpenGexMaterialIndexUnsupported = 'mius',
        kDataOpenGexDuplicateMaterialRef = 'dprf',
        kDataOpenGexMissingMaterialRef = 'msrf',
        kDataOpenGexTargetRefNotLocal = 'trnl',
        kDataOpenGexInvalidTargetStruct = 'ivts',
        kDataOpenGexInvalidKeyKind = 'ivkk',
        kDataOpenGexInvalidCurveType = 'ivct',
        kDataOpenGexKeyCountMismatch = 'kycm',
        kDataOpenGexEmptyKeyStructure = 'emky'
    };

    inline std::string DataResultToString(DataResult result)
    {
        switch (result)
        {
        case kDataOpenGexInvalidUpDirection:
            return "Invalid up direction";
        case kDataOpenGexInvalidForwardDirection:
            return "Invalid forward direction";
        case kDataOpenGexInvalidTranslationKind:
            return "Invalid translation kind";
        case kDataOpenGexInvalidRotationKind:
            return "Invalid rotation kind";
        case kDataOpenGexInvalidScaleKind:
            return "Invalid scale kind";
        case kDataOpenGexDuplicateLod:
            return "Duplicate LOD structure";
        case kDataOpenGexMissingLodSkin:
            return "Missing LOD skin structure";
        case kDataOpenGexMissingLodMorph:
            return "Missing LOD morph structure";
        case kDataOpenGexDuplicateMorph:
            return "Duplicate morph structure";
        case kDataOpenGexUndefinedLightType:
            return "Undefined light type";
        case kDataOpenGexUndefinedCurve:
            return "Undefined curve type";
        case kDataOpenGexUndefinedAtten:
            return "Undefined attenuation type";
        case kDataOpenGexDuplicateVertexArray:
            return "Duplicate vertex array structure";
        case kDataOpenGexPositionArrayRequired:
            return "Position array structure required";
        case kDataOpenGexVertexCountUnsupported:
            return "Vertex count unsupported";
        case kDataOpenGexIndexValueUnsupported:
            return "Index value unsupported";
        case kDataOpenGexIndexArrayRequired:
            return "Index array structure required";
        case kDataOpenGexVertexCountMismatch:
            return "Vertex count mismatch";
        case kDataOpenGexBoneCountMismatch:
            return "Bone count mismatch";
        case kDataOpenGexBoneWeightCountMismatch:
            return "Bone weight count mismatch";
        case kDataOpenGexInvalidBoneRef:
            return "Invalid bone reference";
        case kDataOpenGexInvalidObjectRef:
            return "Invalid object reference";
        case kDataOpenGexInvalidMaterialRef:
            return "Invalid material reference";
        case kDataOpenGexMaterialIndexUnsupported:
            return "Material index unsupported";
        case kDataOpenGexDuplicateMaterialRef:
            return "Duplicate material reference";
        case kDataOpenGexMissingMaterialRef:
            return "Missing material reference";
        case kDataOpenGexTargetRefNotLocal:
            return "Target reference not local";
        case kDataOpenGexInvalidTargetStruct:
            return "Invalid target structure";
        case kDataOpenGexInvalidKeyKind:
            return "Invalid key kind";
        case kDataOpenGexInvalidCurveType:
            return "Invalid curve type";
        case kDataOpenGexKeyCountMismatch:
            return "Key count mismatch";
        case kDataOpenGexEmptyKeyStructure:
            return "Empty key structure";
        default:
            return Terathon::DataResultToString(result);
        }
    }

    class MaterialStructure;
    class ObjectStructure;
    class GeometryObjectStructure;
    class LightObjectStructure;
    class CameraObjectStructure;
    class OpenGexDataDescription;

    class OpenGexStructure : public Structure
    {
    protected:
        OpenGexStructure(StructureType type);

    public:
        ~OpenGexStructure();
    };

    class MetricStructure : public OpenGexStructure
    {
    private:
        std::string metricKey;

    public:
        MetricStructure();
        ~MetricStructure();

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class NameStructure : public OpenGexStructure
    {
    private:
        std::string name;

    public:
        NameStructure();
        ~NameStructure();

        const std::string& GetName(void) const
        {
            return (name);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class ObjectRefStructure : public OpenGexStructure
    {
    private:
        Structure* targetStructure;

    public:
        ObjectRefStructure();
        ~ObjectRefStructure();

        Structure* GetTargetStructure(void) const
        {
            return (targetStructure);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class MaterialRefStructure : public OpenGexStructure
    {
    private:
        uint32                   materialIndex;
        const MaterialStructure* targetStructure;

    public:
        MaterialRefStructure();
        ~MaterialRefStructure();

        uint32 GetMaterialIndex(void) const
        {
            return (materialIndex);
        }

        const MaterialStructure* GetTargetStructure(void) const
        {
            return (targetStructure);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class AnimatableStructure : public OpenGexStructure
    {
    protected:
        AnimatableStructure(StructureType type);
        ~AnimatableStructure();

    public:
        virtual void UpdateAnimation(const OpenGexDataDescription* dataDescription, const float* data) = 0;
    };

    class MatrixStructure : public AnimatableStructure
    {
    private:
        bool objectFlag;

    protected:
        Transform3D matrixValue;

        MatrixStructure(StructureType type);

    public:
        ~MatrixStructure();

        bool GetObjectFlag(void) const
        {
            return (objectFlag);
        }

        const Transform3D& GetMatrix(void) const
        {
            return (matrixValue);
        }

        bool ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
    };

    class TransformStructure final : public MatrixStructure
    {
    private:
        Array<Transform3D, 1> transformArray;

    public:
        TransformStructure();
        ~TransformStructure();

        int32 GetTransformCount(void) const
        {
            return (transformArray.GetArrayElementCount());
        }

        const Transform3D& GetTransform(int32 index = 0) const
        {
            return (transformArray[index]);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, const float* data) override;
    };

    class TranslationStructure final : public MatrixStructure
    {
    private:
        std::string translationKind;

    public:
        TranslationStructure();
        ~TranslationStructure();

        const std::string& GetTranslationKind(void) const
        {
            return (translationKind);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, const float* data) override;
    };

    class RotationStructure final : public MatrixStructure
    {
    private:
        std::string rotationKind;

    public:
        RotationStructure();
        ~RotationStructure();

        const std::string& GetRotationKind(void) const
        {
            return (rotationKind);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, const float* data) override;
    };

    class ScaleStructure final : public MatrixStructure
    {
    private:
        std::string scaleKind;

    public:
        ScaleStructure();
        ~ScaleStructure();

        const std::string& GetScaleKind(void) const
        {
            return (scaleKind);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, const float* data) override;
    };

    class MorphWeightStructure : public AnimatableStructure
    {
    private:
        uint32 morphIndex;
        float  morphWeight;

    public:
        MorphWeightStructure();
        ~MorphWeightStructure();

        uint32 GetMorphIndex(void) const
        {
            return (morphIndex);
        }

        float GetMorphWeight(void) const
        {
            return (morphWeight);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, const float* data) override;
    };

    class NodeStructure : public OpenGexStructure
    {
    private:
        std::string nodeName;

        Transform3D nodeTransform;
        Transform3D objectTransform;
        Transform3D inverseObjectTransform;

        virtual const ObjectStructure* GetObjectStructure(void) const;

        void CalculateNodeTransforms(const OpenGexDataDescription* dataDescription);

    protected:
        NodeStructure(StructureType type);

    public:
        NodeStructure();
        ~NodeStructure();

        const Transform3D& GetNodeTransform(void) const
        {
            return (nodeTransform);
        }

        const Transform3D& GetObjectTransform(void) const
        {
            return (objectTransform);
        }

        const Transform3D& GetInverseObjectTransform(void) const
        {
            return (inverseObjectTransform);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateNodeTransforms(const OpenGexDataDescription* dataDescription);
    };

    class BoneNodeStructure : public NodeStructure
    {
    public:
        BoneNodeStructure();
        ~BoneNodeStructure();
    };

    class GeometryNodeStructure : public NodeStructure
    {
    private:
        bool visibleFlag[2];
        bool shadowFlag[2];
        bool motionBlurFlag[2];

        GeometryObjectStructure*           geometryObjectStructure;
        Array<const MaterialStructure*, 4> materialStructureArray;
        std::list<MorphWeightStructure*>   morphWeightList;

        const ObjectStructure* GetObjectStructure(void) const override;

    public:
        GeometryNodeStructure();
        ~GeometryNodeStructure();

        const GeometryObjectStructure* GetGeometryObjectStructure(void) const
        {
            return (geometryObjectStructure);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        const MorphWeightStructure* FindMorphWeightStructure(uint32 index) const;

        const std::list<MorphWeightStructure*>& GetMorphWeightList() const
        {
            return morphWeightList;
        }
    };

    class LightNodeStructure : public NodeStructure
    {
    private:
        bool shadowFlag[2];

        const LightObjectStructure* lightObjectStructure;

        const ObjectStructure* GetObjectStructure(void) const override;

    public:
        LightNodeStructure();
        ~LightNodeStructure();

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class CameraNodeStructure : public NodeStructure
    {
    private:
        const CameraObjectStructure* cameraObjectStructure;

        const ObjectStructure* GetObjectStructure(void) const override;

    public:
        CameraNodeStructure();
        ~CameraNodeStructure();

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class VertexArrayStructure : public OpenGexStructure
    {
    private:
        std::string attribString;
        uint32      attribIndex;
        uint32      morphIndex;

        int32 vertexCount;
        int32 componentCount;

        char*       arrayStorage;
        float*      floatStorage;
        const void* vertexArrayData;

        bool ValidateAttrib(Range<int32>* componentRange);

    public:
        VertexArrayStructure();
        ~VertexArrayStructure();

        const std::string& GetAttribString(void) const
        {
            return (attribString);
        }

        uint32 GetAttribIndex(void) const
        {
            return (attribIndex);
        }

        uint32 GetMorphIndex(void) const
        {
            return (morphIndex);
        }

        int32 GetVertexCount(void) const
        {
            return (vertexCount);
        }

        int32 GetComponentCount(void) const
        {
            return (componentCount);
        }

        const void* GetVertexArrayData(void) const
        {
            return (vertexArrayData);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class IndexArrayStructure : public OpenGexStructure
    {
    private:
        uint32      materialIndex;
        uint64      restartIndex;
        std::string frontFace;

        int32       indexCount;
        char*       arrayStorage;
        const void* indexArrayData;

    public:
        IndexArrayStructure();
        ~IndexArrayStructure();

        uint32 GetMaterialIndex(void) const
        {
            return (materialIndex);
        }

        uint64 GetRestartIndex(void) const
        {
            return (restartIndex);
        }

        uint32 GetIndexCount(void) const
        {
            return indexCount;
        }

        const std::string& GetFrontFace(void) const
        {
            return (frontFace);
        }

        const void* GetIndexArrayData(void) const
        {
            return (indexArrayData);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class BoneRefArrayStructure : public OpenGexStructure
    {
    private:
        int32                     boneCount;
        const BoneNodeStructure** boneNodeArray;

    public:
        BoneRefArrayStructure();
        ~BoneRefArrayStructure();

        int32 GetBoneCount(void) const
        {
            return (boneCount);
        }

        const BoneNodeStructure* const* GetBoneNodeArray(void) const
        {
            return (boneNodeArray);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class BoneCountArrayStructure : public OpenGexStructure
    {
    private:
        int32         vertexCount;
        const uint16* boneCountArray;
        uint16*       arrayStorage;

    public:
        BoneCountArrayStructure();
        ~BoneCountArrayStructure();

        int32 GetVertexCount(void) const
        {
            return (vertexCount);
        }

        const uint16* GetBoneCountArray(void) const
        {
            return (boneCountArray);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class BoneIndexArrayStructure : public OpenGexStructure
    {
    private:
        int32         boneIndexCount;
        const uint16* boneIndexArray;
        uint16*       arrayStorage;

    public:
        BoneIndexArrayStructure();
        ~BoneIndexArrayStructure();

        int32 GetBoneIndexCount(void) const
        {
            return (boneIndexCount);
        }

        const uint16* GetBoneIndexArray(void) const
        {
            return (boneIndexArray);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class BoneWeightArrayStructure : public OpenGexStructure
    {
    private:
        int32        boneWeightCount;
        const float* boneWeightArray;

    public:
        BoneWeightArrayStructure();
        ~BoneWeightArrayStructure();

        int32 GetBoneWeightCount(void) const
        {
            return (boneWeightCount);
        }

        const float* GetBoneWeightArray(void) const
        {
            return (boneWeightArray);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class SkeletonStructure : public OpenGexStructure
    {
    private:
        const BoneRefArrayStructure* boneRefArrayStructure;
        const TransformStructure*    transformStructure;

    public:
        SkeletonStructure();
        ~SkeletonStructure();

        const BoneRefArrayStructure* GetBoneRefArrayStructure(void) const
        {
            return (boneRefArrayStructure);
        }

        const TransformStructure* GetTransformStructure(void) const
        {
            return (transformStructure);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class SkinStructure : public OpenGexStructure
    {
    private:
        Transform3D skinTransform;

        const SkeletonStructure*        skeletonStructure;
        const BoneCountArrayStructure*  boneCountArrayStructure;
        const BoneIndexArrayStructure*  boneIndexArrayStructure;
        const BoneWeightArrayStructure* boneWeightArrayStructure;

    public:
        SkinStructure();
        ~SkinStructure();

        const Transform3D& GetSkinTransform(void) const
        {
            return (skinTransform);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class MorphStructure : public OpenGexStructure
    {
    private:
        uint32 morphIndex;

        bool   baseFlag;
        uint32 baseIndex;

        std::string morphName;

    public:
        typedef uint32 KeyType;

        MorphStructure();
        ~MorphStructure();

        KeyType GetKey(void) const
        {
            return (morphIndex);
        }

        uint32 GetMorphIndex(void) const
        {
            return (morphIndex);
        }

        bool GetBaseFlag(void) const
        {
            return (baseFlag);
        }

        uint32 GetBaseIndex(void) const
        {
            return (baseIndex);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class MeshStructure : public OpenGexStructure
    {
    private:
        uint32                          meshLevel;
        std::string                     meshPrimitive;
        std::list<IndexArrayStructure*> indexArrayList;
        SkinStructure*                  skinStructure;

    public:
        typedef uint32 KeyType;

        MeshStructure();
        ~MeshStructure();

        KeyType GetKey(void) const
        {
            return (meshLevel);
        }

        const std::list<IndexArrayStructure*>* GetIndexArrayList(void) const
        {
            return (&indexArrayList);
        }

        SkinStructure* GetSkinStructure(void) const
        {
            return (skinStructure);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class ObjectStructure : public OpenGexStructure
    {
    protected:
        ObjectStructure(StructureType type);

    public:
        ~ObjectStructure();
    };

    class GeometryObjectStructure : public ObjectStructure
    {
    private:
        bool visibleFlag;
        bool shadowFlag;
        bool motionBlurFlag;

        std::unordered_map<MeshStructure::KeyType, MeshStructure*>  meshMap;
        std::unordered_map<MeshStructure::KeyType, MorphStructure*> morphMap;

    public:
        GeometryObjectStructure();
        ~GeometryObjectStructure();

        const std::unordered_map<MeshStructure::KeyType, MeshStructure*>* GetMeshMap(void) const
        {
            return (&meshMap);
        }

        const std::unordered_map<MorphStructure::KeyType, MorphStructure*>* GetMorphMap(void) const
        {
            return (&morphMap);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class LightObjectStructure : public ObjectStructure
    {
    private:
        std::string typeString;
        bool        shadowFlag;

    public:
        LightObjectStructure();
        ~LightObjectStructure();

        bool GetShadowFlag(void) const
        {
            return (shadowFlag);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class CameraObjectStructure : public ObjectStructure
    {
    private:
        float projectionDistance;
        float nearDepth;
        float farDepth;

    public:
        CameraObjectStructure();
        ~CameraObjectStructure();

        float GetProjectionDistance(void) const
        {
            return (projectionDistance);
        }

        float GetNearDepth(void) const
        {
            return (nearDepth);
        }

        float GetFarDepth(void) const
        {
            return (farDepth);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class AttribStructure : public OpenGexStructure
    {
    private:
        std::string attribString;

    protected:
        AttribStructure(StructureType type);

    public:
        ~AttribStructure();

        const std::string& GetAttribString(void) const
        {
            return (attribString);
        }

        bool ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
    };

    class ParamStructure : public AttribStructure
    {
    private:
        float param;

    public:
        ParamStructure();
        ~ParamStructure();

        float GetParam(void) const
        {
            return (param);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class ColorStructure : public AttribStructure
    {
    private:
        ColorRGBA color;

    public:
        ColorStructure();
        ~ColorStructure();

        const ColorRGBA& GetColor(void) const
        {
            return (color);
        }

        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class SpectrumStructure : public AttribStructure
    {
    private:
        Range<uint32> wavelengthRange;

    public:
        SpectrumStructure();
        ~SpectrumStructure();

        const Range<uint32>& GetWavelengthRange(void) const
        {
            return (wavelengthRange);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class TextureStructure : public AttribStructure
    {
    private:
        uint32      texcoordIndex;
        std::string textureSwizzle;
        std::string textureAddress[3];
        std::string textureBorder;

        std::string textureName;
        Transform3D texcoordTransform;

        void SetTextureName(const OpenGexDataDescription* dataDescription, const char* name);

    public:
        TextureStructure();
        ~TextureStructure();

        uint32 GetTexcoordIndex(void) const
        {
            return (texcoordIndex);
        }

        const std::string& GetTextureSwizzle(void) const
        {
            return (textureSwizzle);
        }

        const std::string& GetTextureAddress(int32 coord) const
        {
            return (textureAddress[coord]);
        }

        const std::string& GetTextureBorder(void) const
        {
            return (textureBorder);
        }

        const std::string& GetTextureName(void) const
        {
            return (textureName);
        }

        const Transform3D& GetTexcoordTransform(void) const
        {
            return (texcoordTransform);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class AttenStructure : public OpenGexStructure
    {
    private:
        std::string attenKind;
        std::string curveType;

        float beginParam;
        float endParam;

        float scaleParam;
        float offsetParam;

        float constantParam;
        float linearParam;
        float quadraticParam;

        float powerParam;

    public:
        AttenStructure();
        ~AttenStructure();

        const std::string& GetAttenKind(void) const
        {
            return (attenKind);
        }

        const std::string& GetCurveType(void) const
        {
            return (curveType);
        }

        float GetBeginParam(void) const
        {
            return (beginParam);
        }

        float GetEndParam(void) const
        {
            return (endParam);
        }

        float GetScaleParam(void) const
        {
            return (scaleParam);
        }

        float GetOffsetParam(void) const
        {
            return (offsetParam);
        }

        float GetConstantParam(void) const
        {
            return (constantParam);
        }

        float GetLinearParam(void) const
        {
            return (linearParam);
        }

        float GetQuadraticParam(void) const
        {
            return (quadraticParam);
        }

        float GetPowerParam(void) const
        {
            return (powerParam);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class MaterialStructure : public OpenGexStructure
    {
    private:
        bool        twoSidedFlag;
        const char* materialName;

    public:
        MaterialStructure();
        ~MaterialStructure();

        bool GetTwoSidedFlag(void) const
        {
            return (twoSidedFlag);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class KeyStructure : public OpenGexStructure
    {
    private:
        std::string keyKind;

        bool scalarFlag;

    public:
        KeyStructure();
        ~KeyStructure();

        const std::string& GetKeyKind(void) const
        {
            return (keyKind);
        }

        bool GetScalarFlag(void) const
        {
            return (scalarFlag);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class CurveStructure : public OpenGexStructure
    {
    private:
        std::string curveType;

        const KeyStructure* keyValueStructure;
        const KeyStructure* keyControlStructure[2];
        const KeyStructure* keyTensionStructure;
        const KeyStructure* keyContinuityStructure;
        const KeyStructure* keyBiasStructure;

    protected:
        int32 keyDataElementCount;

        CurveStructure(StructureType type);

    public:
        ~CurveStructure();

        const std::string& GetCurveType(void) const
        {
            return (curveType);
        }

        const KeyStructure* GetKeyValueStructure(void) const
        {
            return (keyValueStructure);
        }

        const KeyStructure* GetKeyControlStructure(int32 index) const
        {
            return (keyControlStructure[index]);
        }

        const KeyStructure* GetKeyTensionStructure(void) const
        {
            return (keyTensionStructure);
        }

        const KeyStructure* GetKeyContinuityStructure(void) const
        {
            return (keyContinuityStructure);
        }

        const KeyStructure* GetKeyBiasStructure(void) const
        {
            return (keyBiasStructure);
        }

        int32 GetKeyDataElementCount(void) const
        {
            return (keyDataElementCount);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class TimeStructure : public CurveStructure
    {
    public:
        TimeStructure();
        ~TimeStructure();

        DataResult ProcessData(DataDescription* dataDescription) override;

        int32 CalculateInterpolationParameter(float time, float* param) const;
    };

    class ValueStructure : public CurveStructure
    {
    public:
        ValueStructure();
        ~ValueStructure();

        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, int32 index, float param, AnimatableStructure* target) const;
    };

    class TrackStructure : public OpenGexStructure
    {
    private:
        StructureRef targetRef;

        AnimatableStructure*  targetStructure;
        const TimeStructure*  timeStructure;
        const ValueStructure* valueStructure;

    public:
        TrackStructure();
        ~TrackStructure();

        const StructureRef& GetTargetRef(void) const
        {
            return (targetRef);
        }

        AnimatableStructure* GetTargetStructure(void) const
        {
            return (targetStructure);
        }

        const TimeStructure* GetTimeStructure(void) const
        {
            return (timeStructure);
        }

        const ValueStructure* GetValueStructure(void) const
        {
            return (valueStructure);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        void UpdateAnimation(const OpenGexDataDescription* dataDescription, float time) const;
    };

    class AnimationStructure : public OpenGexStructure
    {
    private:
        uint32 clipIndex;

        bool  beginFlag;
        bool  endFlag;
        float beginTime;
        float endTime;

        std::list<TrackStructure*> trackList;

    public:
        AnimationStructure();
        ~AnimationStructure();

        uint32 GetClipIndex(void) const
        {
            return (clipIndex);
        }

        void AddTrack(TrackStructure* track)
        {
            trackList.push_back(track);
        }

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;

        Range<float> GetAnimationTimeRange(void) const;
        void         UpdateAnimation(const OpenGexDataDescription* dataDescription, float time) const;
    };

    class ClipStructure : public OpenGexStructure
    {
    private:
        uint32 clipIndex;

        float       frameRate;
        std::string clipName;

    public:
        ClipStructure();
        ~ClipStructure();

        bool       ValidateProperty(const DataDescription* dataDescription, std::string_view identifier, DataType* type, void** value) override;
        bool       ValidateSubstructure(const DataDescription* dataDescription, const Structure* structure) const override;
        DataResult ProcessData(DataDescription* dataDescription) override;
    };

    class OpenGexDataDescription : public DataDescription
    {
    private:
        float       distanceScale;
        float       angleScale;
        float       timeScale;
        std::string upDirection;
        std::string forwardDirection;
        Vector2D    redChromaticity;
        Vector2D    greenChromaticity;
        Vector2D    blueChromaticity;
        Vector2D    whiteChromaticity;

        bool     colorInitFlag;
        Matrix3D colorMatrix;

        std::list<AnimationStructure*> animationList;

        DataResult ProcessData(void) override;

    public:
        OpenGexDataDescription();
        ~OpenGexDataDescription();

        float GetDistanceScale(void) const
        {
            return (distanceScale);
        }

        void SetDistanceScale(float scale)
        {
            distanceScale = scale;
        }

        float GetAngleScale(void) const
        {
            return (angleScale);
        }

        void SetAngleScale(float scale)
        {
            angleScale = scale;
        }

        float GetTimeScale(void) const
        {
            return (timeScale);
        }

        void SetTimeScale(float scale)
        {
            timeScale = scale;
        }

        const std::string& GetUpDirection(void) const
        {
            return (upDirection);
        }

        void SetUpDirection(const char* direction)
        {
            upDirection = direction;
        }

        const std::string& GetForwardDirection(void) const
        {
            return (forwardDirection);
        }

        void SetForwardDirection(const char* direction)
        {
            forwardDirection = direction;
        }

        const Vector2D& GetRedChromaticity(void) const
        {
            return (redChromaticity);
        }

        void SetRedChromaticity(const Vector2D& chromaticity)
        {
            redChromaticity = chromaticity;
        }

        const Vector2D& GetGreenChromaticity(void) const
        {
            return (greenChromaticity);
        }

        void SetGreenChromaticity(const Vector2D& chromaticity)
        {
            greenChromaticity = chromaticity;
        }

        const Vector2D& GetBlueChromaticity(void) const
        {
            return (blueChromaticity);
        }

        void SetBlueChromaticity(const Vector2D& chromaticity)
        {
            blueChromaticity = chromaticity;
        }

        const Vector2D& GetWhiteChromaticity(void) const
        {
            return (whiteChromaticity);
        }

        void SetWhiteChromaticity(const Vector2D& chromaticity)
        {
            whiteChromaticity = chromaticity;
        }

        void AddAnimation(AnimationStructure* structure)
        {
            animationList.push_back(structure);
        }

        const std::list<AnimationStructure*>* GetAnimationList(void) const
        {
            return (&animationList);
        }

        Structure* CreateStructure(std::string_view identifier) const override;
        bool       ValidateTopLevelStructure(const Structure* structure) const override;

        void AdjustTransform(Transform3D& transform) const;
        void ConvertColor(ColorRGB& color);

        Range<float> GetAnimationTimeRange(int32 clip) const;
        void         UpdateAnimation(int32 clip, float time) const;
    };
} // namespace OpenGEX

#endif
