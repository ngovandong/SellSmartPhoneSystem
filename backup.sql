USE [master]
GO
/****** Object:  Database [vandong]    Script Date: 7/10/2021 12:25:08 PM ******/
CREATE DATABASE [vandong]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'vandong', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\vandong.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'vandong_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\vandong_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [vandong] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [vandong].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [vandong] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [vandong] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [vandong] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [vandong] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [vandong] SET ARITHABORT OFF 
GO
ALTER DATABASE [vandong] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [vandong] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [vandong] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [vandong] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [vandong] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [vandong] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [vandong] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [vandong] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [vandong] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [vandong] SET  ENABLE_BROKER 
GO
ALTER DATABASE [vandong] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [vandong] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [vandong] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [vandong] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [vandong] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [vandong] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [vandong] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [vandong] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [vandong] SET  MULTI_USER 
GO
ALTER DATABASE [vandong] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [vandong] SET DB_CHAINING OFF 
GO
ALTER DATABASE [vandong] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [vandong] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [vandong] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [vandong] SET QUERY_STORE = OFF
GO
USE [vandong]
GO
/****** Object:  Table [dbo].[CUSTOMER]    Script Date: 7/10/2021 12:25:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CUSTOMER](
	[customer_id] [int] IDENTITY(1,1) NOT NULL,
	[customer_name] [nvarchar](30) NULL,
	[phonenumber] [nvarchar](20) NULL,
	[address] [nvarchar](60) NULL,
 CONSTRAINT [PK__CUSTOMER__CD65CB85519F195F] PRIMARY KEY CLUSTERED 
(
	[customer_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[INVOICE]    Script Date: 7/10/2021 12:25:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[INVOICE](
	[invoice_id] [int] IDENTITY(1,1) NOT NULL,
	[customer_id] [int] NULL,
	[date_buy] [date] NULL,
	[total] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[invoice_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[INVOICE_DETAIL]    Script Date: 7/10/2021 12:25:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[INVOICE_DETAIL](
	[invoice_id] [int] NOT NULL,
	[smartphone_id] [int] NOT NULL,
	[qty] [int] NULL,
	[unit_price] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[invoice_id] ASC,
	[smartphone_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[SMARTPHONE]    Script Date: 7/10/2021 12:25:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SMARTPHONE](
	[smartphone_id] [int] IDENTITY(1,1) NOT NULL,
	[smartphone_name] [nvarchar](50) NULL,
	[brand] [nvarchar](20) NULL,
	[price] [int] NULL,
	[qty] [int] NULL,
	[qty_sold] [int] NULL,
	[RAM] [smallint] NULL,
	[ROM] [smallint] NULL,
	[battery] [smallint] NULL,
	[screen] [numeric](5, 2) NULL,
	[color] [nvarchar](20) NULL,
	[cameras] [smallint] NULL,
	[warranty] [nvarchar](20) NULL,
	[others] [nvarchar](50) NULL,
	[deleted] [bit] NOT NULL,
 CONSTRAINT [PK__SMARTPHO__F7EB820AAF889148] PRIMARY KEY CLUSTERED 
(
	[smartphone_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[CUSTOMER] ON 

INSERT [dbo].[CUSTOMER] ([customer_id], [customer_name], [phonenumber], [address]) VALUES (1, N'Ngo Van Dong', N'0779689559', N'Dien Phuong Dien Ban Quang Nam')
INSERT [dbo].[CUSTOMER] ([customer_id], [customer_name], [phonenumber], [address]) VALUES (2, N'Nguyen Thanh Hung', N'0326715829', N'112 Pham Nhu Tang Da Nang')
INSERT [dbo].[CUSTOMER] ([customer_id], [customer_name], [phonenumber], [address]) VALUES (3, N'Le Thi Minh Anh', N'0369867584', N'32 Nguyen Luong Bang')
INSERT [dbo].[CUSTOMER] ([customer_id], [customer_name], [phonenumber], [address]) VALUES (4, N'Tran Hoang Anh', N'0331647895', N'K82 Nguyen Luong Bang')
INSERT [dbo].[CUSTOMER] ([customer_id], [customer_name], [phonenumber], [address]) VALUES (5, N'Dang Van Lam', N'0369872567', N'35 Dien Bien Phu ')
INSERT [dbo].[CUSTOMER] ([customer_id], [customer_name], [phonenumber], [address]) VALUES (6, N'Duong Phu Ninh', N'0125768569', N'K144 Nguyen Luong Bang')
SET IDENTITY_INSERT [dbo].[CUSTOMER] OFF
GO
SET IDENTITY_INSERT [dbo].[INVOICE] ON 

INSERT [dbo].[INVOICE] ([invoice_id], [customer_id], [date_buy], [total]) VALUES (1, 1, CAST(N'2020-12-29' AS Date), 5990000)
INSERT [dbo].[INVOICE] ([invoice_id], [customer_id], [date_buy], [total]) VALUES (2, 2, CAST(N'2020-12-29' AS Date), 59560000)
INSERT [dbo].[INVOICE] ([invoice_id], [customer_id], [date_buy], [total]) VALUES (3, 3, CAST(N'2020-12-29' AS Date), 19970000)
INSERT [dbo].[INVOICE] ([invoice_id], [customer_id], [date_buy], [total]) VALUES (4, 4, CAST(N'2020-12-29' AS Date), 82150000)
INSERT [dbo].[INVOICE] ([invoice_id], [customer_id], [date_buy], [total]) VALUES (5, 5, CAST(N'2020-12-29' AS Date), 15000000)
INSERT [dbo].[INVOICE] ([invoice_id], [customer_id], [date_buy], [total]) VALUES (6, 6, CAST(N'2020-12-30' AS Date), 36370000)
SET IDENTITY_INSERT [dbo].[INVOICE] OFF
GO
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (1, 20, 1, 5990000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (2, 9, 2, 4790000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (2, 16, 2, 24990000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (3, 20, 2, 5990000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (3, 22, 1, 7990000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (4, 8, 2, 3590000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (4, 16, 3, 24990000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (5, 11, 1, 15000000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (6, 2, 1, 26990000)
INSERT [dbo].[INVOICE_DETAIL] ([invoice_id], [smartphone_id], [qty], [unit_price]) VALUES (6, 6, 2, 4690000)
GO
SET IDENTITY_INSERT [dbo].[SMARTPHONE] ON 

INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (1, N'Samsung Galaxy Note 10+', N'Samsung', 16490000, 11, 146, 12, 256, 4300, CAST(6.80 AS Numeric(5, 2)), N'black/grey', 3, N'12 months', N'Android 9 (Pie)  ', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (2, N'Samsung Galaxy Note 20 Ultra', N'Samsung', 26990000, 27, 18, 8, 256, 4500, CAST(6.90 AS Numeric(5, 2)), N'black/grey/pink', 3, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (3, N'Samsung Galaxy M51', N'Samsung', 9490000, 41, 34, 8, 128, 7000, CAST(6.70 AS Numeric(5, 2)), N'black/white', 3, N'12 months', N'', 1)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (5, N'Samsung Galaxy A10s', N'Samsung', 3690000, 12, 58, 2, 32, 4000, CAST(6.20 AS Numeric(5, 2)), N'black/red/green', 2, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (6, N'Samsung Galaxy A21s', N'Samsung', 4690000, 3, 50, 3, 32, 4000, CAST(6.50 AS Numeric(5, 2)), N'black/white/blue', 4, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (7, N'Vsmart Aris', N'Vsmart', 7490000, 24, 146, 8, 128, 4000, CAST(6.39 AS Numeric(5, 2)), N'black/green/blue', 4, N'18 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (8, N'Vsmart Joy 4', N'Vsmart', 3590000, 15, 176, 4, 64, 5000, CAST(6.53 AS Numeric(5, 2)), N'black/white/blue', 4, N'18 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (9, N'Vsmart Live 4', N'Vsmart', 4790000, 3, 278, 6, 64, 5000, CAST(6.50 AS Numeric(5, 2)), N'black/white/blue', 4, N'18 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (10, N'Xiaomi Mi 9', N'Xiaomi', 11900000, 3, 34, 6, 64, 3300, CAST(6.39 AS Numeric(5, 2)), N'black/white', 2, N'12 months', N'', 1)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (11, N'Iphone XR', N'Iphone', 15000000, 3, 44, 3, 64, 2942, CAST(6.10 AS Numeric(5, 2)), N'red', 1, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (12, N'Iphone 11', N'Iphone', 19990000, 2, 57, 4, 64, 3110, CAST(6.10 AS Numeric(5, 2)), N'red/white/black', 2, N'12 months', N'ios', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (14, N'iPhone Xr 64GB', N'Iphone', 14490000, 12, 24, 3, 64, 2942, CAST(6.10 AS Numeric(5, 2)), N'red/black/white', 1, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (15, N'Samsung galaxy j7 2016', N'Samsung', 6000000, 0, 27, 3, 16, 2300, CAST(5.50 AS Numeric(5, 2)), N'black/white/yellow', 1, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (16, N'Iphone 12', N'Iphone', 24990000, 6, 29, 4, 128, 2815, CAST(6.10 AS Numeric(5, 2)), N'red/white/green', 2, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (17, N'Iphone 12 Pro', N'Iphone', 30990000, 1, 65, 4, 128, 2815, CAST(6.10 AS Numeric(5, 2)), N'blue/grey/white', 3, N'12 months', N'', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (18, N'ealme 7', N'Realme', 5990000, 40, 3, 8, 128, 5000, CAST(6.50 AS Numeric(5, 2)), N'red', 4, N'12 months', N'', 1)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (19, N'OPPO Reno4', N'Oppo', 8490000, 30, 0, 8, 128, 4015, CAST(6.40 AS Numeric(5, 2)), N'black/violet/blue', 3, N'12 months', N'', 1)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (20, N'Realme 7', N'Realme', 5990000, 21, 9, 6, 128, 5000, CAST(6.50 AS Numeric(5, 2)), N'red', 4, N'12 months', N'hang moi ve', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (22, N'Vivo V20', N'Vivo', 7990000, 4, 12, 8, 128, 4000, CAST(6.44 AS Numeric(5, 2)), N'black/blue', 3, N'12 months', N've sang hom nay', 0)
INSERT [dbo].[SMARTPHONE] ([smartphone_id], [smartphone_name], [brand], [price], [qty], [qty_sold], [RAM], [ROM], [battery], [screen], [color], [cameras], [warranty], [others], [deleted]) VALUES (23, N'iaomi Redmi Note 9S', N'Xiaomi', 5690000, 30, 0, 6, 128, 5200, CAST(6.67 AS Numeric(5, 2)), N'red/blue', 4, N'12 months', N've hoi sang', 0)
SET IDENTITY_INSERT [dbo].[SMARTPHONE] OFF
GO
ALTER TABLE [dbo].[INVOICE] ADD  CONSTRAINT [DF_INVOICE_total]  DEFAULT ((0)) FOR [total]
GO
ALTER TABLE [dbo].[INVOICE_DETAIL] ADD  CONSTRAINT [DF_INVOICE_DETAIL_unit_price]  DEFAULT ((0)) FOR [unit_price]
GO
ALTER TABLE [dbo].[SMARTPHONE] ADD  CONSTRAINT [DF_SMARTPHONE_delete]  DEFAULT ((0)) FOR [deleted]
GO
ALTER TABLE [dbo].[INVOICE]  WITH CHECK ADD  CONSTRAINT [FK_INVOICE_CUSTOMER] FOREIGN KEY([customer_id])
REFERENCES [dbo].[CUSTOMER] ([customer_id])
GO
ALTER TABLE [dbo].[INVOICE] CHECK CONSTRAINT [FK_INVOICE_CUSTOMER]
GO
ALTER TABLE [dbo].[INVOICE_DETAIL]  WITH CHECK ADD  CONSTRAINT [FK__INVOICE_D__invoi__1CBC4616] FOREIGN KEY([invoice_id])
REFERENCES [dbo].[INVOICE] ([invoice_id])
GO
ALTER TABLE [dbo].[INVOICE_DETAIL] CHECK CONSTRAINT [FK__INVOICE_D__invoi__1CBC4616]
GO
ALTER TABLE [dbo].[INVOICE_DETAIL]  WITH CHECK ADD  CONSTRAINT [FK__INVOICE_D__smart__1DB06A4F] FOREIGN KEY([smartphone_id])
REFERENCES [dbo].[SMARTPHONE] ([smartphone_id])
GO
ALTER TABLE [dbo].[INVOICE_DETAIL] CHECK CONSTRAINT [FK__INVOICE_D__smart__1DB06A4F]
GO
/****** Object:  StoredProcedure [dbo].[procupdatedata]    Script Date: 7/10/2021 12:25:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create proc [dbo].[procupdatedata] -- proc =procedure
@invoice_id int, -- declare variable
@smartphone_id int,
@qty int
as
	begin
		declare @price int
		insert into INVOICE_DETAIL(invoice_id,smartphone_id,qty)
		values (@invoice_id,@smartphone_id,@qty)
		select @price=price from SMARTPHONE where smartphone_id=@smartphone_id
		update INVOICE_DETAIL set unit_price=@price where invoice_id=@invoice_id and smartphone_id=@smartphone_id
		update INVOICE set total=total+ @price*@qty where invoice_id=@invoice_id
	end
GO
USE [master]
GO
ALTER DATABASE [vandong] SET  READ_WRITE 
GO
