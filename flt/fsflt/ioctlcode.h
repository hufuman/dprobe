//
// N.B. This file include IOCTL from SDK, WDK.
//

#ifndef _IOCTLCODE_H_
#define _IOCTLCODE_H_

//
// FROM WDK 7600
//

//
// SCSI
//

#define FILE_DEVICE_SCSI 0x0000001b

#define IOCTL_SCSI_EXECUTE_IN   ((FILE_DEVICE_SCSI << 16) + 0x0011)
#define IOCTL_SCSI_EXECUTE_OUT  ((FILE_DEVICE_SCSI << 16) + 0x0012)
#define IOCTL_SCSI_EXECUTE_NONE ((FILE_DEVICE_SCSI << 16) + 0x0013)

//
// SMART support in atapi
//

#define IOCTL_SCSI_MINIPORT_SMART_VERSION           ((FILE_DEVICE_SCSI << 16) + 0x0500)
#define IOCTL_SCSI_MINIPORT_IDENTIFY                ((FILE_DEVICE_SCSI << 16) + 0x0501)
#define IOCTL_SCSI_MINIPORT_READ_SMART_ATTRIBS      ((FILE_DEVICE_SCSI << 16) + 0x0502)
#define IOCTL_SCSI_MINIPORT_READ_SMART_THRESHOLDS   ((FILE_DEVICE_SCSI << 16) + 0x0503)
#define IOCTL_SCSI_MINIPORT_ENABLE_SMART            ((FILE_DEVICE_SCSI << 16) + 0x0504)
#define IOCTL_SCSI_MINIPORT_DISABLE_SMART           ((FILE_DEVICE_SCSI << 16) + 0x0505)
#define IOCTL_SCSI_MINIPORT_RETURN_STATUS           ((FILE_DEVICE_SCSI << 16) + 0x0506)
#define IOCTL_SCSI_MINIPORT_ENABLE_DISABLE_AUTOSAVE ((FILE_DEVICE_SCSI << 16) + 0x0507)
#define IOCTL_SCSI_MINIPORT_SAVE_ATTRIBUTE_VALUES   ((FILE_DEVICE_SCSI << 16) + 0x0508)
#define IOCTL_SCSI_MINIPORT_EXECUTE_OFFLINE_DIAGS   ((FILE_DEVICE_SCSI << 16) + 0x0509)
#define IOCTL_SCSI_MINIPORT_ENABLE_DISABLE_AUTO_OFFLINE ((FILE_DEVICE_SCSI << 16) + 0x050a)
#define IOCTL_SCSI_MINIPORT_READ_SMART_LOG          ((FILE_DEVICE_SCSI << 16) + 0x050b)
#define IOCTL_SCSI_MINIPORT_WRITE_SMART_LOG         ((FILE_DEVICE_SCSI << 16) + 0x050c)


//
// Mount Point Manager 
//

#define MOUNTMGR_DEVICE_NAME                        L"\\Device\\MountPointManager"
#define MOUNTMGR_DOS_DEVICE_NAME                    L"\\\\.\\MountPointManager"

#define MOUNTMGRCONTROLTYPE                         0x0000006D // 'm'
#define MOUNTDEVCONTROLTYPE                         0x0000004D // 'M'

//
// These are the IOCTLs supported by the mount point manager.
//

#define IOCTL_MOUNTMGR_CREATE_POINT                 CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS                CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_QUERY_POINTS                 CTL_CODE(MOUNTMGRCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY         CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER            CTL_CODE(MOUNTMGRCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS          CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED   CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED   CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_CHANGE_NOTIFY                CTL_CODE(MOUNTMGRCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE      CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES    CTL_CODE(MOUNTMGRCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION  CTL_CODE(MOUNTMGRCONTROLTYPE, 11, METHOD_BUFFERED, FILE_READ_ACCESS)

//
// The following IOCTL is supported by mounted devices.
//

#define IOCTL_MOUNTDEV_QUERY_DEVICE_NAME    CTL_CODE(MOUNTDEVCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)

//
// Output structure for IOCTL_MOUNTDEV_QUERY_DEVICE_NAME.
//

typedef struct _MOUNTDEV_NAME {
    USHORT  NameLength;
    WCHAR   Name[1];
} MOUNTDEV_NAME, *PMOUNTDEV_NAME;

//
// Devices that wish to be mounted should report this GUID in
// IoRegisterDeviceInterface.
//

#ifdef DEFINE_GUID

DEFINE_GUID(MOUNTDEV_MOUNTED_DEVICE_GUID, 0x53f5630d, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

#endif


#endif  // NTDDI_VERSION >= NTDDI_WIN2K

#if (NTDDI_VERSION >= NTDDI_WINXP)

#define IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATH        CTL_CODE(MOUNTMGRCONTROLTYPE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATHS       CTL_CODE(MOUNTMGRCONTROLTYPE, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)

//
// Output structure for IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATH and
// IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATHS.
//

typedef struct _MOUNTMGR_VOLUME_PATHS {
    ULONG   MultiSzLength;
    WCHAR   MultiSz[1];
} MOUNTMGR_VOLUME_PATHS, *PMOUNTMGR_VOLUME_PATHS;


#define MOUNTMGR_IS_DOS_VOLUME_NAME(s) (    \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 96 &&                   \
     (s)->Buffer[1] == '\\'                 \
    )

#define MOUNTMGR_IS_DOS_VOLUME_NAME_WB(s) ( \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 98 &&                   \
     (s)->Buffer[1] == '\\'                 \
    )

#define MOUNTMGR_IS_NT_VOLUME_NAME(s) (     \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 96 &&                   \
     (s)->Buffer[1] == '?'                  \
    )

#define MOUNTMGR_IS_NT_VOLUME_NAME_WB(s) (  \
     MOUNTMGR_IS_VOLUME_NAME(s) &&          \
     (s)->Length == 98 &&                   \
     (s)->Buffer[1] == '?'                  \
    )

#endif  // NTDDI_VERSION >= NTDDI_WINXP

#if (NTDDI_VERSION >= NTDDI_WS03)

#define IOCTL_MOUNTMGR_SCRUB_REGISTRY               CTL_CODE(MOUNTMGRCONTROLTYPE, 14, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_QUERY_AUTO_MOUNT             CTL_CODE(MOUNTMGRCONTROLTYPE, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTMGR_SET_AUTO_MOUNT               CTL_CODE(MOUNTMGRCONTROLTYPE, 16, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

//
// Input / Output structure for querying / setting the auto-mount setting
//

typedef enum _MOUNTMGR_AUTO_MOUNT_STATE {
        Disabled = 0,
        Enabled
        } MOUNTMGR_AUTO_MOUNT_STATE;

typedef struct _MOUNTMGR_QUERY_AUTO_MOUNT {
    MOUNTMGR_AUTO_MOUNT_STATE   CurrentState;
    } MOUNTMGR_QUERY_AUTO_MOUNT, *PMOUNTMGR_QUERY_AUTO_MOUNT;

typedef struct _MOUNTMGR_SET_AUTO_MOUNT {
    MOUNTMGR_AUTO_MOUNT_STATE   NewState;
    } MOUNTMGR_SET_AUTO_MOUNT, *PMOUNTMGR_SET_AUTO_MOUNT;

#endif  // NTDDI_VERSION >= NTDDI_WS03

#if (NTDDI_VERSION >= NTDDI_WIN7)

#define IOCTL_MOUNTMGR_BOOT_DL_ASSIGNMENT               CTL_CODE(MOUNTMGRCONTROLTYPE, 17, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_TRACELOG_CACHE                   CTL_CODE(MOUNTMGRCONTROLTYPE, 18, METHOD_BUFFERED, FILE_READ_ACCESS)

#endif  // NTDDI_VERSION >= NTDDI_WIN7