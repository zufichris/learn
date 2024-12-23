
# Next.js Template

This is a Next.js template with a well-structured folder architecture to help you start your new projects quickly and efficiently.



## Folder Structure

```
@types
  └── theme.ts
app
  ├── globals.css
  ├── layout.tsx
  └── page.tsx
components
  └── ui
      └── button.tsx
config
  ├── env.ts
lib
  ├── actions
      └── user.actions.ts
  ├── db
      └── db.ts
  └── services
      └── UserService.ts
public
theme
  └── index.ts
utils
  └── cn.ts
.gitignore
eslint.config.mjs
next-env.d.ts
next.config.ts
tsconfig.json
tailwind.config.ts
README.md
postcss.config.mjs
package.json
package-lock.json
```

## Description

This template is designed to provide a solid foundation for building scalable and maintainable Next.js applications. The folder structure is organized to separate concerns and enhance code readability and maintainability.

## Folder Details

- **@types**: Contains TypeScript type definitions.
  - `theme.ts`: Type definitions for the theme.

- **app**: Contains global styles, layout, and main pages.
  - `globals.css`: Global CSS styles.
  - `layout.tsx`: Main layout component.
  - `page.tsx`: Main page component.

- **components**: Contains reusable UI components.
  - `ui/button.tsx`: A button component.

- **config**: Contains configuration files.
  - `env.ts`: Environment configuration.

- **lib**: Contains business logic, database access, and services.
  - `actions/user.actions.ts`: User-related actions.
  - `db/db.ts`: Database connection and configuration.
  - `services/UserService.ts`: User service for handling user-related operations.

- **public**: Contains public assets like images, fonts, etc.

- **theme**: Contains theme-related files.
  - `index.ts`: Theme configuration.

- **utils**: Contains utility functions.
  - `cn.ts`: Utility function for class names.

## Configuration Files

- **.gitignore**: Specifies files and directories to be ignored by Git.
- **eslint.config.mjs**: ESLint configuration.
- **next-env.d.ts**: Next.js environment types.
- **next.config.ts**: Next.js configuration.
- **tsconfig.json**: TypeScript configuration.
- **tailwind.config.ts**: Tailwind CSS configuration.
- **postcss.config.mjs**: PostCSS configuration.
- **package.json**: Project dependencies and scripts.
- **package-lock.json**: Locked versions of project dependencies.

## Getting Started

To get started with this template, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/zufichris/nextjs-template.git ./your-project-name
   ```

2. Navigate to the project directory:
   ```bash
   cd your-repo-name
   ```

3. Install dependencies:
   ```bash
   npm install
   ```

4. Start the development server:
   ```bash
   npm run dev
   ```

## Contributing

If you have any suggestions or improvements, feel free to create a pull request or open an issue.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
```

This README file provides an overview of the folder structure and instructions for getting started with the template. Adjust the details as necessary to fit your specific project and requirements.
